/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 03:06:07 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/21 00:03:47 by bbonaldi         ###   ########.fr       */
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
