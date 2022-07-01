/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:25:06 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/01 23:32:03 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void render_map_component(t_data *mlx, t_xmp_img *img,
			t_map_dimensions *map_dimensions, char character)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (i < map_dimensions->rows)
	{
		j = 0;
		while (j < map_dimensions->columns)
		{
			if (map_dimensions->map_matrix[i][j] == character)
			{
				img->x = (j * DEFAULT_PIXEL_SIZE);
				img->y = (i * DEFAULT_PIXEL_SIZE);
				image_put(mlx, img);
			}
			j++;
		}
		i++;
	}
	
}

void map_render(t_data *mlx, t_map_dimensions *map_dimensions)
{
	render_map_component(mlx, &mlx->img_wall,
		map_dimensions, mlx->img_wall.map_char);
	render_map_component(mlx, &mlx->img_floor,
		map_dimensions, mlx->img_floor.map_char);
	render_map_component(mlx, &mlx->img_player,
		map_dimensions, mlx->img_player.map_char);
	render_map_component(mlx, &mlx->img_collectible,
		map_dimensions, mlx->img_collectible.map_char);
	render_map_component(mlx, &mlx->img_exit,
		map_dimensions, mlx->img_exit.map_char);
}