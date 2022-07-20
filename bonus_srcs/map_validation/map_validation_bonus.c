/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:30:56 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/19 02:07:31 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_map_matrix(t_map_dimensions *map_dimensions)
{
	int	row;

	row = 0;
	if (!(map_dimensions)->map_matrix)
		return ;
	while (row < (map_dimensions)->rows)
	{
		free((map_dimensions)->map_matrix[row]);
		row++;
	}
	free((map_dimensions)->map_matrix);
}

void	create_map_matrix(t_map_dimensions *map_dimensions,
				t_list *map_lines_list, int is_valid_map)
{
	int		row;

	if (is_valid_map == FALSE)
		return ;
	row = 0;
	map_dimensions->map_matrix
		= (char **)malloc(sizeof(char *) * map_dimensions->rows);
	while (row < map_dimensions->rows)
	{	
		map_dimensions->map_matrix[row]
			= ft_strtrim((char *)map_lines_list->content, "\n");
		row++;
		map_lines_list = map_lines_list->next;
	}
}

t_list	*read_map_from_file(char *file_path)
{
	int		fd;
	char	*map_line;
	t_list	*head_map;
	t_list	*node_map;

	if (is_valid_extension(file_path) == FALSE)
		exit_with_message(ERROR_CODE, WRONG_FILE_EXTENSION_ERROR_MESSAGE);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		exit_with_message(ERROR_CODE, NOT_FOUND_FILE_ERROR_MESSAGE);
	head_map = NULL;
	node_map = NULL;
	map_line = NULL;
	while (1)
	{
		map_line = get_next_line(fd);
		if (!map_line)
			break ;
		node_map = ft_lstnew(map_line);
		ft_lstadd_back(&head_map, node_map);
	}
	return (head_map);
}

t_map_dimensions	read_map(t_data *mlx, char *map_path)
{
	int					is_eof;
	t_map_dimensions	map_dimensions;
	t_list				*map_lines_list;
	t_list				*tmp_map_lines_list;

	map_components_init(&mlx->map_components);
	map_dimensions_init(&map_dimensions);
	map_lines_list = read_map_from_file(map_path);
	tmp_map_lines_list = map_lines_list;
	is_eof = FALSE;
	while (tmp_map_lines_list)
	{
		if (tmp_map_lines_list->next == NULL)
			is_eof = TRUE;
		check_map_validators(&mlx->map_components,
			(char *)tmp_map_lines_list->content, is_eof);
		tmp_map_lines_list = tmp_map_lines_list->next;
	}
	check_is_valid_map(&mlx->map_components);
	assign_map_dimensions(&map_dimensions, mlx->map_components);
	create_map_matrix(&map_dimensions, map_lines_list,
		mlx->map_components.is_valid_map);
	ft_lstclear(&map_lines_list, &free);
	return (map_dimensions);
}
