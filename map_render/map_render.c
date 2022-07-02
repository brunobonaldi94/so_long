/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:25:06 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/02 05:59:52 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void save_coordinates_list(t_data *mlx, t_xmp_img *img, t_coordinates counters,
// 	int *count)
// {
// 	t_coordinates coordinates;
	
// 	coordinates.x = img->coordinates.x;
// 	coordinates.y = img->coordinates.y;
// 	if (counters.y == 0 || counters.y == mlx->map_dimensions.rows - 1
// 		|| counters.x == 0 || counters.x == mlx->map_dimensions.columns - 1)
// 		return;
// 	img->coordinates_list[*count] = coordinates;
// 	*count += 1; 
// }

t_coordinates	save_coordinates_list(t_coordinates coordinates)
{
	t_coordinates new_coordinates;
	
	new_coordinates.x = coordinates.x;
	new_coordinates.y = coordinates.y;
	return (new_coordinates);
}

void render_map_component(t_data *mlx, t_xmp_img *img,
			t_map_dimensions *map_dimensions, char character)
{
	t_coordinates counters;
	int count;
	
	counters.x = 0;
	counters.y = 0;
	count = 0;
	img->coordinates_list = (t_coordinates *)malloc(sizeof(t_coordinates) *
		img->count);
	while (counters.y < map_dimensions->rows)
	{
		counters.x = 0;
		while (counters.x < map_dimensions->columns)
		{
			if (map_dimensions->map_matrix[counters.y][counters.x] == character)
			{
				img->coordinates.x = (counters.x * DEFAULT_PIXEL_SIZE);
				img->coordinates.y = (counters.y * DEFAULT_PIXEL_SIZE);
				image_put(mlx, img);
				img->coordinates_list[count++] = 
					save_coordinates_list(img->coordinates);
			}
			counters.x++;
		}
		counters.y++;
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