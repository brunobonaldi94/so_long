/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:34:31 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/01 23:31:07 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	destroy_images(t_data *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_collectible.mlx_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_exit.mlx_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_floor.mlx_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_player.mlx_img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_wall.mlx_img);
 }

int exit_with_message(int status_code, char *message)
{
	ft_printf(message);
	exit(status_code);
}

int game_exit(t_data *mlx)
{
	destroy_images(mlx);
	destroy_map_matrix(&mlx->map_dimensions);
	destroy_window(mlx);
	destroy_display(mlx);
	exit(0);
	return (0);
}