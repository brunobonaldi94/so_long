/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:25:06 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/30 04:13:35 by bbonaldi         ###   ########.fr       */
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

void wall_render(t_data *mlx, t_map_dimensions *map_dimensions)
{
	t_xmp_img *img;

	img = mlx->img_wall;
	img = image_init(IMG_WALL_PATH);
	image_render(mlx, img);
	render_map_component(mlx, img, map_dimensions, MAP_WALL_CHAR);
	image_destroy(mlx, &img);
}

void	player_render(t_data *mlx, t_map_dimensions *map_dimensions)
{
	t_xmp_img *img;

	img = mlx->img_player;
	img = image_init(IMG_PLAYER_PATH);
	image_render(mlx, img);
	render_map_component(mlx, img, map_dimensions, MAP_PLAYER_CHAR);
	image_destroy(mlx, &img);
}

void	floor_render(t_data *mlx, t_map_dimensions *map_dimensions)
{
	t_xmp_img *img;

	img = mlx->img_floor;
	img = image_init(IMG_FLOOR_PATH);
	image_render(mlx, img);
	render_map_component(mlx, img, map_dimensions, MAP_FLOOR_CHAR);
	image_destroy(mlx, &img);
}

void	exit_render(t_data *mlx, t_map_dimensions *map_dimensions)
{
	t_xmp_img *img;

	img = mlx->img_exit;
	img = image_init(IMG_EXIT_PATH);
	image_render(mlx, img);
	render_map_component(mlx, img, map_dimensions, MAP_EXIT_CHAR);
	image_destroy(mlx, &img);
}

void	collectable_render(t_data *mlx, t_map_dimensions *map_dimensions)
{
	t_xmp_img *img;

	img = mlx->img_collectible;
	img = image_init(IMG_COLLECTIBLE_PATH);
	image_render(mlx, img);
	render_map_component(mlx, img, map_dimensions, MAP_COLLECTIBLE_CHAR);
	image_destroy(mlx, &img);
}

int map_init(t_data *mlx, t_map_dimensions *map_dimensions)
{

	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 
	map_dimensions->columns * DEFAULT_PIXEL_SIZE,
	map_dimensions->rows * DEFAULT_PIXEL_SIZE, 
	"so_long bbonaldi");
	if (mlx->win_ptr == NULL)
	{
		free(mlx->win_ptr);
		return (print_error(MLX_ERROR));
	}
	wall_render(mlx, map_dimensions);
	floor_render(mlx, map_dimensions);
	player_render(mlx, map_dimensions);
	exit_render(mlx, map_dimensions);
	collectable_render(mlx, map_dimensions);
 	return (SUCCES_CODE);
}

int	map_render(t_data *mlx, t_map_dimensions **map_dimensions)
{
	int	map_result;

	map_result = SUCCES_CODE;
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (print_error(MLX_ERROR));
	map_result = map_init(mlx, *map_dimensions);
	destroy_map_matrix(map_dimensions);
	return (map_result);
}