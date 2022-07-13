/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 03:06:07 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/12 22:44:19 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	destroy_window(t_data *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx->win_ptr = NULL;
}

void	destroy_display(t_data *mlx)
{
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
}

void	free_coordinates(t_data *mlx)
{
	free(mlx->img_collectible.coordinates_list);
	free(mlx->img_exit.coordinates_list);
	free(mlx->img_floor.coordinates_list);
	free(mlx->img_player.coordinates_list);
	free(mlx->img_wall.coordinates_list);
}

void	destroy_images(t_data *mlx)
{
	free_coordinates(mlx);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_collectible.mlx_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_exit.mlx_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_floor.mlx_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_player.mlx_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_wall.mlx_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_moves.mlx_img);
}
