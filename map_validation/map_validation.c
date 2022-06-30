/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:30:56 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/30 03:37:05 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	debug(t_valid_components map_components, char *where)
{
	ft_printf("========================%s=====================",where);
	ft_printf("\n%d-has_exit;",map_components.has_exit);
	ft_printf("\n%d-has_collectible;",map_components.has_collectible);
	ft_printf("\n%d-has_player_starting_position;",map_components.has_player_starting_position);
	ft_printf("\n%d-has_valid_char;",map_components.has_valid_char);
	ft_printf("\n%d-has_minimal_components;",map_components.has_minimal_components);
	ft_printf("\nmap_dimensions-c:%d|r:%d;",map_components.map_dimensions.columns, map_components.map_dimensions.rows);
	ft_printf("\n%d-is_rect;",map_components.is_rect);
	ft_printf("\n%d-is_surrounded_by_wall;",map_components.is_surrounded_by_wall);
	ft_printf("\n%d-is_valid_map;",map_components.is_valid_map);
}
void	print_map(t_map_dimensions *map_dimensions, int is_valid_map)
{
	int j = 0;
	if (is_valid_map == FALSE)
		return ;
	while (j < map_dimensions->rows)
	{
		ft_printf("row:%d-%s\n", j, map_dimensions->map_matrix[j]);
		j++;
	}
}
//##################
void	destroy_map_matrix(t_map_dimensions **map_dimensions)
{
	int	row;

	row = 0;
	if (!(*map_dimensions)->map_matrix)
		return ;
	while (row < (*map_dimensions)->rows)
	{
		free((*map_dimensions)->map_matrix[row]);
		row++;
	}
	free((*map_dimensions)->map_matrix);
	free(*map_dimensions);
}

void	create_map_matrix(t_map_dimensions **map_components,
			t_list *map_lines_list, int is_valid_map)
{
 	int					row;
 	t_map_dimensions	*current_map_dimension;
	t_list				*tmp_map_lines_list;

	if (is_valid_map == FALSE)
		return ;
 	current_map_dimension = *map_components;
	row = 0;
 	current_map_dimension->map_matrix = 
		(char **)malloc(sizeof(char *) * current_map_dimension->rows);
	while (row < current_map_dimension->rows)
	{
		
		current_map_dimension->map_matrix[row] = 
			ft_strtrim((char *)map_lines_list->content, "\n");
		row++;
		tmp_map_lines_list = map_lines_list->next;
		ft_lstdelone(map_lines_list, &free);
		map_lines_list = tmp_map_lines_list;
	}
}

t_list	*read_map_from_file(char *file_path)
{
	int		fd;
	char	*map_line;
	t_list	*head_map;
	t_list	*node_map;

	fd = open(file_path, O_RDONLY);
	head_map = NULL;
	node_map = NULL;
	map_line = NULL;
	while (1)
	{
		map_line = get_next_line(fd);
		if (!map_line)
			break;
		node_map = ft_lstnew(map_line);
		ft_lstadd_back(&head_map, node_map);
	}
	return (head_map);
}

t_map_dimensions	*read_map(char *map_path)
{
 	int		is_eof;
	t_valid_components	map_components;
	t_map_dimensions	*map_dimensions;
	t_list	*map_lines_list;
	t_list	*tmp_map_lines_list;

	map_components_init(&map_components);
	map_dimensions_init(&map_dimensions);
 	map_lines_list = read_map_from_file(map_path);
	tmp_map_lines_list = map_lines_list;
	is_eof = FALSE;
	while (tmp_map_lines_list)
	{
 		if (tmp_map_lines_list->next == NULL)
			is_eof = TRUE;
		check_map_validators(&map_components,
			(char *)tmp_map_lines_list->content, is_eof);
		tmp_map_lines_list = tmp_map_lines_list->next;
	}
 	check_is_valid_map(&map_components);
	assign_map_dimensions(&map_dimensions, map_components);
	create_map_matrix(&map_dimensions, map_lines_list,
		map_components.is_valid_map);
	print_map(map_dimensions, map_components.is_valid_map);
	//destroy_map_matrix(&map_dimensions);
 	return (map_dimensions);
}