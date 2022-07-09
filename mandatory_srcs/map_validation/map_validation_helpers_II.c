/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_helpers_II.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 04:05:54 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/09 05:05:48 by bbonaldi         ###   ########.fr       */
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

int	map_has_minimal_components(t_valid_components *map_components)
{
	if (is_valid_component(map_components->count_collectibles)
		&& is_valid_component(map_components->count_exit)
		&& is_valid_component(map_components->has_player_starting_position))
		return (TRUE);
	return (FALSE);
}

int	is_rectangule(t_valid_components *map_components)
{
	if (map_components->is_rect == FALSE)
		return (FALSE);
	if (map_components->map_dimensions.columns > 0
		&& map_components->map_dimensions.rows > 0
		&& map_components->map_dimensions.columns
		!= map_components->map_dimensions.rows)
		return (TRUE);
	return (FALSE);
}
