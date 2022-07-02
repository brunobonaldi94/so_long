/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_checkers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:30:56 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/02 03:57:55 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_minimal_components(t_valid_components *map_components,
			char component)
{
	if (is_valid_map_component(component) == FALSE)
	{
		map_components->has_valid_char = FALSE;
		map_components->is_valid_map = FALSE;
		return ;
	}
	if (component == MAP_COLLECTIBLE_CHAR)
		map_components->count_collectibles++;
	else if (component == MAP_EXIT_CHAR)
		map_components->count_exit++;
	else if (component == MAP_PLAYER_CHAR)
		map_components->has_player_starting_position = TRUE;
	else if (component == MAP_WALL_CHAR)
		map_components->count_internal_walls++;
	else if (component == MAP_FLOOR_CHAR)
		map_components->count_floor++;
	if (is_valid_component(map_components->count_collectibles)
		&& is_valid_component(map_components->count_exit)
		&& is_valid_component(map_components->has_player_starting_position))
		map_components->has_minimal_components = TRUE;
}

void	check_is_rectangule(t_valid_components *map_components,
			t_map_dimensions current_map_dimensions, int is_eof)
{
	int	columns;
	int	rows;

	columns = current_map_dimensions.columns;
	rows = current_map_dimensions.rows;
	if (columns != map_components->map_dimensions.columns 
		&& rows != 0 && is_eof == FALSE)
	{
		map_components->is_rect = FALSE;
		map_components->is_valid_map = FALSE;
		return ;
	}
	if (is_eof == FALSE)
		map_components->map_dimensions.columns = columns;
	map_components->map_dimensions.rows++;
	if (is_eof == TRUE 
		&& map_components->map_dimensions.columns > 0
		&& map_components->map_dimensions.rows > 0
		&& map_components->map_dimensions.columns 
			!= map_components->map_dimensions.rows)
		map_components->is_rect = TRUE;
}

void	check_is_surrounded_by_wall(t_valid_components *map_components,
			t_map_dimensions current_map_dimensions, char component)
{
	int	current_column;
	int current_row;
	int	is_valid;
	
	current_column = current_map_dimensions.columns;
	current_row = current_map_dimensions.rows;
	is_valid = TRUE;
	if (current_row == 0 && component != MAP_WALL_CHAR)
		is_valid = FALSE;
	if (current_column == 0 && component != MAP_WALL_CHAR)
		is_valid = FALSE;
	if (map_components->map_dimensions.columns == current_column
			&& map_components->map_dimensions.columns != 0
			&& component != MAP_WALL_CHAR)
		is_valid = FALSE;
	if (is_valid == FALSE)
	{
		map_components->is_surrounded_by_wall = FALSE;
		map_components->is_valid_map = FALSE;
		return ;
	}
	map_components->is_surrounded_by_wall = TRUE;
}

void	check_map_validators(t_valid_components *map_components,
			char *map_line, int is_eof) 
{
	t_map_dimensions	current_map_dimensions;

	current_map_dimensions.columns = 0;
	current_map_dimensions.rows = map_components->map_dimensions.rows;
	if (map_components->is_valid_map == FALSE)
		return ;
	while (*map_line)
	{
		if (*map_line == '\n')
		{
			map_line++;
			continue;
		}
		check_minimal_components(map_components, *map_line);
		check_is_surrounded_by_wall(map_components, current_map_dimensions,
			*map_line);
		map_line++;
		current_map_dimensions.columns++;
	}
	check_is_rectangule(map_components, current_map_dimensions, is_eof);
}

int	check_is_valid_map(t_valid_components *map_components)
{
	if (map_components->is_valid_map == FALSE)
		return (FALSE);
	if (is_valid_component(map_components->has_minimal_components)
		&& is_valid_component(map_components->is_rect)
		&& is_valid_component(map_components->is_surrounded_by_wall))
	{
		map_components->is_valid_map = TRUE;
	}
	else
		map_components->is_valid_map = FALSE;
	return (map_components->is_valid_map);
}
