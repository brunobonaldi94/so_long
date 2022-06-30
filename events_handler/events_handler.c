/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:24:00 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/30 02:17:31 by bbonaldi         ###   ########.fr       */
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

int	deal_key_press(int key, t_data *mlx)
{
    if (key == KEY_SCAPE)
		deal_close(mlx);
	else if (key == KEY_W)
		ft_printf("pressed w");
	else if (key == KEY_A)
		ft_printf("pressed a");
	else if (key == KEY_S)
		ft_printf("pressed s");
	else if (key == KEY_D)
		ft_printf("pressed d");
    return (0);
}

int deal_close(t_data *mlx)
{
	destroy_window(mlx);
	destroy_display(mlx);
	exit(0);
	return (0);
}

void	handle_events(t_data *mlx)
{
	mlx_hook(mlx->win_ptr, KEY_PRESS_EVENT, (1L<<0), &deal_key_press, mlx);
	mlx_hook(mlx->win_ptr, DESTROY_NOTIFY_EVENT, (1L<<17), &deal_close, mlx);
}