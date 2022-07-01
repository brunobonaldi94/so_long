/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:25:06 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/01 04:24:16 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void render_map_component(t_data *mlx, t_xmp_img **img,
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
				(*img)->x = (j * DEFAULT_PIXEL_SIZE);
				(*img)->y = (i * DEFAULT_PIXEL_SIZE);
				image_put(mlx, *img);
			}
			j++;
		}
		i++;
	}
	
}

void	map_character_render(t_data *mlx, t_xmp_img *img,
			t_map_dimensions *map_dimensions)
{
	image_render(mlx, img);
	render_map_component(mlx, &img, map_dimensions, img->map_char);
	image_destroy(mlx, img);
}

void	map_characters_init(t_data *mlx)
{
	mlx->img_wall = image_init(IMG_WALL_PATH, MAP_WALL_CHAR);
	mlx->img_floor = image_init(IMG_FLOOR_PATH, MAP_FLOOR_CHAR);
	mlx->img_player = image_init(IMG_PLAYER_PATH, MAP_PLAYER_CHAR);
	mlx->img_collectible = image_init(IMG_COLLECTIBLE_PATH, MAP_COLLECTIBLE_CHAR);
	mlx->img_exit = image_init(IMG_EXIT_PATH, MAP_EXIT_CHAR);
}

int map_init(t_data *mlx, t_map_dimensions *map_dimensions)
{

	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
	(map_dimensions)->columns * DEFAULT_PIXEL_SIZE,
	(map_dimensions)->rows * DEFAULT_PIXEL_SIZE,
	"so_long bbonaldi");
	if (mlx->win_ptr == NULL)
	{
		free(mlx->win_ptr);
		return (print_error(MLX_ERROR));
	}
	map_character_render(mlx, &mlx->img_wall, map_dimensions);
	map_character_render(mlx, &mlx->img_floor, map_dimensions);
	map_character_render(mlx, &mlx->img_player, map_dimensions);
	map_character_render(mlx, &mlx->img_collectible, map_dimensions);
	map_character_render(mlx, &mlx->img_exit, map_dimensions);
 	return (SUCCES_CODE);
}

int	map_render(t_data *mlx, t_map_dimensions *map_dimensions)
{
	int	map_result;

	map_result = SUCCES_CODE;
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (print_error(MLX_ERROR));
	map_characters_init(mlx);
 	map_result = map_init(mlx, map_dimensions);
	return (map_result);
}