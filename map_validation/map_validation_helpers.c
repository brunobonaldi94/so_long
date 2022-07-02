/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:30:56 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/02 18:48:57 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_component(int component)
{
	return (component > 0);
}

int	is_valid_map_component(int component)
{
	if (component == MAP_COLLECTIBLE_CHAR || component == MAP_FLOOR_CHAR
		|| component == MAP_EXIT_CHAR || component == MAP_PLAYER_CHAR
		|| component == MAP_WALL_CHAR)
		return (TRUE);
	return (FALSE);
}

void	map_dimensions_init(t_map_dimensions *map_dimensions)
{
	(map_dimensions)->rows = 0;
	(map_dimensions)->columns = 0;
	(map_dimensions)->map_matrix = NULL;
}

void	map_components_init(t_valid_components *map_components)
{
	map_components->count_collectibles = 0;
	map_components->count_exit = 0;
	map_components->count_walls = 0;
	map_components->count_floor = 0;
	map_components->is_rect = -1;
	map_components->has_player_starting_position = -1;
	map_components->map_dimensions.rows = 0;
	map_components->map_dimensions.columns = 0;
	map_components->map_dimensions.map_matrix = NULL;
	map_components->has_minimal_components = -1;
	map_components->has_valid_char = -1;
	map_components->is_surrounded_by_wall = -1;
	map_components->is_valid_map = -1;
}

void	assign_map_dimensions(t_map_dimensions *map_dimensions,
			t_valid_components map_components)
{
	(map_dimensions)->rows = map_components.map_dimensions.rows;
	(map_dimensions)->columns = map_components.map_dimensions.columns;
}
