/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_enemy_patrol_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 04:19:34 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/20 02:20:12 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_enemy_in_map(t_data *mlx, t_coordinates coordinates)
{
	mlx->map_dimensions.map_matrix[coordinates.y][coordinates.x]
		= MAP_ENEMY_CHAR;
}

int	put_enemy_count(t_data *mlx, t_coordinates c)
{
	int	count_enemy;

	count_enemy = 0;
	if (mlx->map_dimensions.map_matrix[c.y - 1][c.x] == MAP_FLOOR_CHAR)
	{
		put_enemy_in_map(mlx, (t_coordinates){c.x, c.y - 1});
		count_enemy++;
	}
	else if (mlx->map_dimensions.map_matrix[c.y][c.x - 1] == MAP_FLOOR_CHAR)
	{
		put_enemy_in_map(mlx, (t_coordinates){c.x - 1, c.y});
		count_enemy++;
	}
	else if (mlx->map_dimensions.map_matrix[c.y + 1][c.x] == MAP_FLOOR_CHAR)
	{
		put_enemy_in_map(mlx, (t_coordinates){c.x, c.y + 1});
		count_enemy++;
	}
	else if (mlx->map_dimensions.map_matrix[c.y][c.x + 1] == MAP_FLOOR_CHAR)
	{
		put_enemy_in_map(mlx, (t_coordinates){c.x + 1, c.y});
		count_enemy++;
	}
	return (count_enemy);
}

int	get_enemy_count(t_data *mlx)
{
	t_coordinates	c;
	int				count_enemy;

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
				count_enemy += put_enemy_count(mlx, c);
			}
			c.x++;
		}
		c.y++;
	}
	return (count_enemy);
}
