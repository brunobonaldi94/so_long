/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:59:57 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/14 01:03:55 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_characters_init(t_data *mlx)
{
	mlx->img_wall = image_init(IMG_WALL_PATH, MAP_WALL_CHAR,
			mlx->map_components.count_walls);
	mlx->img_floor = image_init(IMG_FLOOR_PATH, MAP_FLOOR_CHAR,
			mlx->map_components.count_floor);
	mlx->img_player = image_init(IMG_PLAYER_RIGHT_PATH, MAP_PLAYER_CHAR,
			mlx->map_components.has_player_starting_position);
	mlx->img_collectible = image_init(IMG_COLLECTIBLE_PATH,
			MAP_COLLECTIBLE_CHAR, mlx->map_components.count_collectibles);
	mlx->img_exit = image_init(IMG_EXIT_PATH, MAP_EXIT_CHAR,
			mlx->map_components.count_exit);
	mlx->img_moves = image_init(IMG_NUMBER_ZERO_PATH, '0', 1);
	mlx->img_footer = image_init(IMG_FOOTER_PATH, 'F', 1);
}

void	map_characters_load(t_data *mlx)
{
	map_characters_init(mlx);
	mlx->game_play.count_moves = 0;
	mlx->game_play.can_exit = FALSE;
	mlx->game_play.start_count_collectibles
		= mlx->map_components.count_collectibles;
	image_render(mlx, &mlx->img_floor);
	image_render(mlx, &mlx->img_exit);
	image_render(mlx, &mlx->img_collectible);
	image_render(mlx, &mlx->img_player);
	image_render(mlx, &mlx->img_wall);
	image_render(mlx, &mlx->img_moves);
	image_render(mlx, &mlx->img_footer);
}
