/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:33:11 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/10 00:36:07 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_in_map_boundaries(t_data *mlx, t_coordinates coordinates_adder)
{
	int	y_boundaries;
	int	x_boundaries;

	x_boundaries = (mlx->map_dimensions.columns * DEFAULT_PIXEL_SIZE)
		- DEFAULT_PIXEL_SIZE;
	y_boundaries = (mlx->map_dimensions.rows * DEFAULT_PIXEL_SIZE)
		- DEFAULT_PIXEL_SIZE;
	if ((mlx->img_player.coordinates.x + coordinates_adder.x
			< DEFAULT_PIXEL_SIZE
			|| mlx->img_player.coordinates.x + coordinates_adder.x
			>= x_boundaries))
		coordinates_adder.x = 0;
	if ((mlx->img_player.coordinates.y + coordinates_adder.y
			< DEFAULT_PIXEL_SIZE
			|| mlx->img_player.coordinates.y + coordinates_adder.y
			>= y_boundaries))
		coordinates_adder.y = 0;
	return (coordinates_adder.x + coordinates_adder.y);
}

void	coordinates_assign(t_coordinates *coordinates, int x, int y)
{
	coordinates->x = x;
	coordinates->y = y;
}

void	calculate_new_coordinates(t_xmp_img *img,
	t_coordinates coordinates_adder)
{
	img->coordinates.x += coordinates_adder.x;
	img->coordinates.y += coordinates_adder.y;
}

int	is_there_an_object(t_data *mlx, t_xmp_img *img,
			t_coordinates coordinates_adder)
{
	t_coordinates	new_cordinates;
	int				i;

	i = 0;
	coordinates_assign(&new_cordinates, mlx->img_player.coordinates.x
		+ coordinates_adder.x,
		mlx->img_player.coordinates.y + coordinates_adder.y);
	while (i < img->count)
	{
		if (img->coordinates_list[i].x == new_cordinates.x
			&& img->coordinates_list[i].y == new_cordinates.y)
		{
			if (img->map_char == MAP_COLLECTIBLE_CHAR)
			{
				img->coordinates_list[i].x = 0;
				img->coordinates_list[i].y = 0;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

void	update_map_matrix(t_data *mlx, t_xmp_img *img)
{
	int	row;
	int	column;

	row = img->coordinates.y / DEFAULT_PIXEL_SIZE;
	column = img->coordinates.x / DEFAULT_PIXEL_SIZE;
	mlx->map_dimensions.map_matrix[row][column] = img->map_char;
}
