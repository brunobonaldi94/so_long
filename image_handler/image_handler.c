/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:59:57 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/02 06:06:33 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_xmp_img	image_init(char *file_path, char map_char, int count)
{
	t_xmp_img img;
	
	img.height = 0;
	img.width = 0;
	img.count = count;
	img.coordinates_list = NULL;
	img.relative_path = file_path;
	img.mlx_img = NULL;
	img.coordinates.x = 0;
	img.coordinates.y = 0;
	img.map_char = map_char;
	return (img);
}

void	image_destroy(t_data *mlx, t_xmp_img *img)
{
	mlx_destroy_image(mlx->mlx_ptr, (img)->mlx_img);
	//free(img);
	img = NULL;
}

void	image_render(t_data *mlx, t_xmp_img *img)
{
	if (mlx->win_ptr != NULL)
	{
 		img->mlx_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			img->relative_path, &img->width, &img->height);
	}
}

void	image_put(t_data *mlx, t_xmp_img *img)
{
	if (mlx->win_ptr != NULL)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->mlx_img,
			img->coordinates.x, img->coordinates.y);
	}
}

void	map_characters_init(t_data *mlx)
{
 	mlx->img_wall = image_init(IMG_WALL_PATH, MAP_WALL_CHAR, 
		mlx->map_components.count_internal_walls);
	mlx->img_floor = image_init(IMG_FLOOR_PATH, MAP_FLOOR_CHAR,
		mlx->map_components.count_floor);
	mlx->img_player = image_init(IMG_PLAYER_PATH, MAP_PLAYER_CHAR,
		mlx->map_components.has_player_starting_position);
	mlx->img_collectible = image_init(IMG_COLLECTIBLE_PATH, 
		MAP_COLLECTIBLE_CHAR, mlx->map_components.count_collectibles);
	mlx->img_exit = image_init(IMG_EXIT_PATH, MAP_EXIT_CHAR, 
		mlx->map_components.count_exit);
}

void	map_characters_load(t_data *mlx)
{
	map_characters_init(mlx);
	image_render(mlx, &mlx->img_floor);
	image_render(mlx, &mlx->img_exit);
	image_render(mlx, &mlx->img_collectible);
	image_render(mlx, &mlx->img_player);
	image_render(mlx, &mlx->img_wall);
	mlx->game_play.count_moves = 0;
	mlx->game_play.count_collectibles_acquired = 0;
	mlx->game_play.can_exit = FALSE;
}


void	image_full_cycle(t_data *mlx, t_xmp_img *img)
{
	image_render(mlx,img);
	image_put(mlx, img);
	image_destroy(mlx, img);
}