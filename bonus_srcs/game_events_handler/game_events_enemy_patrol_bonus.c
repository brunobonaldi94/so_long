/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_enemy_patrol_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 04:19:34 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/15 05:06:12 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_enemy_in_map(t_data *mlx, t_coordinates coordinates)
{
	mlx->map_dimensions.map_matrix[coordinates.y][coordinates.x]
		= MAP_ENEMY_CHAR;
}

int	get_enemy_count(t_data *mlx)
{
	t_coordinates c;
	t_coordinates new_c;
	int count_enemy;

	c.y = 0;
	count_enemy = 0;
	while (c.y < mlx->map_dimensions.rows)
	{
		c.x = 0;
		while (c.x < mlx->map_dimensions.columns)
		{
			if (mlx->map_dimensions.map_matrix[c.y][c.x]
				== MAP_COLLECTIBLE_CHAR)
			{
				if (mlx->map_dimensions.map_matrix[c.y - 1][c.x]
					== MAP_FLOOR_CHAR)
				{
					new_c.x = c.x;
					new_c.y = c.y - 1;
					put_enemy_in_map(mlx, new_c);
					count_enemy++;
				}
				else if (mlx->map_dimensions.map_matrix[c.y][c.x - 1]
					== MAP_FLOOR_CHAR)
				{
					new_c.x = c.x  - 1;
					new_c.y = c.y;
					put_enemy_in_map(mlx, new_c);
					count_enemy++;
				}
				else if (mlx->map_dimensions.map_matrix[c.y + 1][c.x]
					== MAP_FLOOR_CHAR)
				{
					new_c.x = c.x;
					new_c.y = c.y + 1;
					put_enemy_in_map(mlx, new_c);
					count_enemy++;
				}
				else if (mlx->map_dimensions.map_matrix[c.y][c.x + 1]
					== MAP_FLOOR_CHAR)
				{
					new_c.x = c.x  + 1;
					new_c.y = c.y;
					put_enemy_in_map(mlx, new_c);
					count_enemy++;
				}
			}
			c.x++;
		}
		c.y++;
	}
	return (count_enemy);
}