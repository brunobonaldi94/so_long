/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 04:42:19 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/10 00:36:07 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_coordinates	save_coordinates(t_coordinates coordinates)
{
	t_coordinates	new_coordinates;

	new_coordinates.x = coordinates.x;
	new_coordinates.y = coordinates.y;
	return (new_coordinates);
}

void	reset_counters(t_data *mlx)
{
	mlx->img_wall.count = 0;
	mlx->img_player.count = 0;
	mlx->img_floor.count = 0;
	mlx->img_exit.count = 0;
	mlx->img_collectible.count = 0;
}

void	add_counters(t_data *mlx, char current_map_char)
{
	if (current_map_char == MAP_FLOOR_CHAR)
				mlx->img_floor.count++;
	else if (current_map_char == MAP_WALL_CHAR)
				mlx->img_wall.count++;
	else if (current_map_char == MAP_PLAYER_CHAR)
				mlx->img_player.count++;
	else if (current_map_char == MAP_EXIT_CHAR)
				mlx->img_exit.count++;
	else if (current_map_char == MAP_COLLECTIBLE_CHAR)
				mlx->img_collectible.count++;
}

void	re_count_map_char(t_data *mlx)
{
	t_coordinates	counters;
	char			current_map_char;

	counters.y = 0;
	reset_counters(mlx);
	while (counters.y < mlx->map_dimensions.rows)
	{
		counters.x = 0;
		while (counters.x < mlx->map_dimensions.columns)
		{
			current_map_char
				= mlx->map_dimensions.map_matrix[counters.y][counters.x];
			add_counters(mlx, current_map_char);
			counters.x++;
		}
		counters.y++;
	}
}
