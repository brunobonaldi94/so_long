/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:24:00 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/02 06:19:09 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_in_map_boundaries(t_data *mlx, t_coordinates coordinates_adder)
{
	int y_boundaries;
	int	x_boundaries;
 
	x_boundaries = (mlx->map_dimensions.columns * DEFAULT_PIXEL_SIZE)
		- DEFAULT_PIXEL_SIZE;
	y_boundaries = (mlx->map_dimensions.rows * DEFAULT_PIXEL_SIZE)
		- DEFAULT_PIXEL_SIZE;
	if ((mlx->img_player.coordinates.x + coordinates_adder.x < DEFAULT_PIXEL_SIZE 
		|| mlx->img_player.coordinates.x + coordinates_adder.x >= x_boundaries))
		coordinates_adder.x = 0;
	if ((mlx->img_player.coordinates.y + coordinates_adder.y < DEFAULT_PIXEL_SIZE
		|| mlx->img_player.coordinates.y + coordinates_adder.y >= y_boundaries))
		coordinates_adder.y = 0;
	return (coordinates_adder.x + coordinates_adder.y);
}

void	coordinates_assign(t_coordinates *coordinates, int x, int y)
{
	coordinates->x = x;
	coordinates->y = y;
}

void calculate_new_coordinates(t_xmp_img *img,
	t_coordinates coordinates_adder)
{
	img->coordinates.x += coordinates_adder.x;
	img->coordinates.y += coordinates_adder.y;
}

int	is_there_an_object(t_data *mlx, t_xmp_img *img,
			t_coordinates coordinates_adder)
{
	t_coordinates new_cordinates;
	int i;

	i = 0;
	coordinates_assign(&new_cordinates, mlx->img_player.coordinates.x +
		coordinates_adder.x, mlx->img_player.coordinates.y + coordinates_adder.y);
	while (i < img->count)
	{
		if (img->coordinates_list[i].x == new_cordinates.x &&
			img->coordinates_list[i].y == new_cordinates.y)
			return (1);
		i++;
	}
	return (0);
}

void	floor_replace_player(t_data *mlx)
{
	mlx->img_floor.coordinates.y = mlx->img_player.coordinates.y;
	mlx->img_floor.coordinates.x = mlx->img_player.coordinates.x;
	image_put(mlx, &mlx->img_floor);
}

void	player_move(t_data *mlx, t_coordinates coordinates_adder)
{
  	if (is_there_an_object(mlx, 
		&mlx->img_wall, coordinates_adder) || (is_there_an_object(mlx, 
		&mlx->img_exit, coordinates_adder) && mlx->game_play.can_exit == FALSE))
		return ;
	if (is_there_an_object(mlx, &mlx->img_collectible, coordinates_adder))
	{
		mlx->game_play.count_collectibles_acquired++;
		if (mlx->game_play.count_collectibles_acquired == 
				mlx->img_collectible.count)
			mlx->game_play.can_exit = TRUE;
	}
	floor_replace_player(mlx);
	calculate_new_coordinates(&mlx->img_player, coordinates_adder);
	image_put(mlx, &mlx->img_player);
	mlx->game_play.count_moves++;
	ft_printf("moves: %d\n", mlx->game_play.count_moves);
	if (is_there_an_object(mlx, 
		&mlx->img_exit, coordinates_adder) && mlx->game_play.can_exit == TRUE)
			game_exit(mlx);
}

int	deal_key_press(int key, t_data *mlx)
{
	t_coordinates coordinates_adder;

    if (key == KEY_SCAPE)
		game_exit(mlx);
	else if (key == KEY_W || key == KEY_UP)
	{
		coordinates_assign(&coordinates_adder, 0, -1 * DEFAULT_PIXEL_SIZE);
		player_move(mlx, coordinates_adder);
	}
	else if (key == KEY_A || key == KEY_LEFT)
	{
		coordinates_assign(&coordinates_adder, -1 * DEFAULT_PIXEL_SIZE, 0);
		player_move(mlx, coordinates_adder);
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
		coordinates_assign(&coordinates_adder, 0, DEFAULT_PIXEL_SIZE);
  		player_move(mlx, coordinates_adder);
	}
	else if (key == KEY_D || key == KEY_RIGHT)
	{
		coordinates_assign(&coordinates_adder, DEFAULT_PIXEL_SIZE, 0);
		player_move(mlx, coordinates_adder);
	}
    return (0);
}

void	handle_events(t_data *mlx)
{
	mlx_hook(mlx->win_ptr, KEY_PRESS_EVENT, (1L<<0), &deal_key_press, mlx);
	mlx_hook(mlx->win_ptr, DESTROY_NOTIFY_EVENT, (1L<<17), &game_exit, mlx);
}