/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_handler_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:24:00 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/21 00:41:03 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	floor_replacer(t_data *mlx,	t_xmp_img *img)
{
	mlx->img_floor.coordinates.y = img->coordinates.y;
	mlx->img_floor.coordinates.x = img->coordinates.x;
	image_put(mlx, &mlx->img_floor);
}

void	player_move(t_data *mlx, t_coordinates coordinates_adder)
{
	floor_replacer(mlx, &mlx->img_player);
	update_map_matrix(mlx, &mlx->img_floor);
	calculate_new_coordinates(&mlx->img_player, coordinates_adder);
	if (coordinates_adder.x < 0 && mlx->img_player.is_right == TRUE)
	{
		image_change_file_path(mlx, &mlx->img_player, IMG_PLAYER_LEFT_PATH);
		mlx->img_player.is_right = FALSE;
	}
	else if (coordinates_adder.x > 0 && mlx->img_player.is_right == FALSE)
	{
		image_change_file_path(mlx, &mlx->img_player, IMG_PLAYER_RIGHT_PATH);
		mlx->img_player.is_right = TRUE;
	}
	image_put(mlx, &mlx->img_player);
	update_map_matrix(mlx, &mlx->img_player);
	put_moves_to_window(mlx, ++mlx->game_play.count_moves);
}

void	player_move_validate(t_data *mlx, t_coordinates coordinates_adder)
{
	if (!is_in_map_boundaries(mlx, coordinates_adder)
		|| is_there_an_object(mlx, mlx->img_wall.map_char, coordinates_adder)
		|| (is_there_an_object(mlx, mlx->img_exit.map_char, coordinates_adder)
			&& mlx->game_play.can_exit == FALSE)
		|| mlx->game_play.game_over == TRUE)
		return ;
	if (is_there_an_object(mlx, mlx->img_collectible.map_char,
			coordinates_adder))
	{
		mlx->game_play.start_count_collectibles--;
		if (mlx->game_play.start_count_collectibles == 0)
			mlx->game_play.can_exit = TRUE;
	}
	else if (is_there_an_object(mlx, mlx->img_exit.map_char, coordinates_adder)
		&& mlx->game_play.can_exit == TRUE)
		game_exit(mlx);
	else if (is_there_an_object(mlx, mlx->img_enemy.map_char,
			coordinates_adder))
	{
		put_dead_player(mlx);
		return ;
	}
	player_move(mlx, coordinates_adder);
}

int	deal_key_press(int key, t_data *mlx)
{
	t_coordinates	coordinates_adder;

	if (key == KEY_SCAPE)
		game_exit(mlx);
	else if (key == KEY_W || key == KEY_UP)
	{
		coordinates_assign(&coordinates_adder, 0, -1 * DEFAULT_PIXEL_SIZE);
		player_move_validate(mlx, coordinates_adder);
	}
	else if (key == KEY_A || key == KEY_LEFT)
	{
		coordinates_assign(&coordinates_adder, -1 * DEFAULT_PIXEL_SIZE, 0);
		player_move_validate(mlx, coordinates_adder);
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
		coordinates_assign(&coordinates_adder, 0, DEFAULT_PIXEL_SIZE);
		player_move_validate(mlx, coordinates_adder);
	}
	else if (key == KEY_D || key == KEY_RIGHT)
	{
		coordinates_assign(&coordinates_adder, DEFAULT_PIXEL_SIZE, 0);
		player_move_validate(mlx, coordinates_adder);
	}
	return (0);
}

void	handle_events(t_data *mlx)
{
	mlx_expose_hook(mlx->win_ptr, &map_re_render, mlx);
	mlx_hook(mlx->win_ptr, KEY_PRESS_EVENT, (1L << 0), &deal_key_press, mlx);
	mlx_hook(mlx->win_ptr, DESTROY_NOTIFY_EVENT, (1L << 17), &game_exit, mlx);
	mlx_loop_hook(mlx->mlx_ptr, &animate_handler, mlx);
}
