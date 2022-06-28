/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:30:56 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/24 18:04:37 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_component(int component)
{
	return (component == TRUE);
}

int	is_valid_map_component(int component)
{
	if (component == MAP_COLLECTIBLE_CHAR || component == MAP_EMPTY_SPACE_CHAR
		|| component == MAP_EXIT_CHAR || component == MAP_PLAYER_CHAR
		|| component == MAP_WALL_CHAR)
 		return (TRUE);
	return (FALSE);
}

void	init_map_components(t_valid_components *map_components)
{
	map_components->has_collectible = -1;
	map_components->has_exit = -1;
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
