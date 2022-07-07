/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:24:00 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/08 00:39:42 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floor_replace_player(t_data *mlx)
{
	mlx->img_floor.coordinates.y = mlx->img_player.coordinates.y;
	mlx->img_floor.coordinates.x = mlx->img_player.coordinates.x;
	image_put(mlx, &mlx->img_floor);
}

void	player_move(t_data *mlx, t_coordinates coordinates_adder)
{
	floor_replace_player(mlx);
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
	mlx->game_play.count_moves++;
	ft_printf("moves: %d\n", mlx->game_play.count_moves);
}

void	player_move_validate(t_data *mlx, t_coordinates coordinates_adder)
{
	if (!is_in_map_boundaries(mlx, coordinates_adder)
		|| is_there_an_object(mlx, &mlx->img_wall, coordinates_adder)
		|| (is_there_an_object(mlx, &mlx->img_exit, coordinates_adder)
			&& mlx->game_play.can_exit == FALSE))
		return ;
	if (is_there_an_object(mlx, &mlx->img_collectible, coordinates_adder))
	{
		mlx->game_play.count_collectibles_acquired++;
		if (mlx->game_play.count_collectibles_acquired
			== mlx->img_collectible.count)
			mlx->game_play.can_exit = TRUE;
	}
	player_move(mlx, coordinates_adder);
	if (is_there_an_object(mlx, &mlx->img_exit, coordinates_adder)
		&& mlx->game_play.can_exit == TRUE)
		game_exit(mlx);
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
	mlx_hook(mlx->win_ptr, KEY_PRESS_EVENT, (1L << 0), &deal_key_press, mlx);
	mlx_hook(mlx->win_ptr, DESTROY_NOTIFY_EVENT, (1L << 17), &game_exit, mlx);
}
