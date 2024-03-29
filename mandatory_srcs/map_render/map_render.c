/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:25:06 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/21 00:02:27 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map_component(t_data *mlx, t_xmp_img *img,
			t_map_dimensions *map_dimensions)
{
	t_coordinates	counters;

	counters.y = 0;
	while (counters.y < map_dimensions->rows)
	{
		counters.x = 0;
		while (counters.x < map_dimensions->columns)
		{
			if (map_dimensions->map_matrix[counters.y][counters.x]
					== img->map_char)
			{
				img->coordinates.x = (counters.x * DEFAULT_PIXEL_SIZE);
				img->coordinates.y = (counters.y * DEFAULT_PIXEL_SIZE);
				image_put(mlx, img);
			}
			counters.x++;
		}
		counters.y++;
	}
}

int	map_render(t_data *mlx)
{
	render_map_component(mlx, &mlx->img_wall, &mlx->map_dimensions);
	render_map_component(mlx, &mlx->img_floor, &mlx->map_dimensions);
	render_map_component(mlx, &mlx->img_player, &mlx->map_dimensions);
	render_map_component(mlx, &mlx->img_collectible, &mlx->map_dimensions);
	render_map_component(mlx, &mlx->img_exit, &mlx->map_dimensions);
	return (0);
}

int	map_re_render(t_data *mlx)
{
	re_count_map_char(mlx);
	map_render(mlx);
	return (0);
}
