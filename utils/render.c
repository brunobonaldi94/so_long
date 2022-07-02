/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:52:34 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/02 19:08:24 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_pixel_put_custom(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)pixel = color;
}

void	mlx_pixel_put_custom_portable(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bits_per_pixel - 8;
	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	while (i > 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bits_per_pixel - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	render_background(t_data *mlx, int color)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (mlx->win_ptr == NULL)
		return ;
	while (y < MLX_WINDOW_HEIGHT)
	{
		x = 0;
		while (x < MLX_WINDOW_WIDTH)
		{
			mlx_pixel_put_custom_portable(&mlx->img, x, y, color);
			x++;
		}
		y++;
	}
}

int	render_rect(t_data *mlx, t_rectangule rect)
{
	int	x;
	int	y;

	if (mlx->win_ptr == NULL)
		return (MLX_ERROR);
	y = rect.y;
	while (y < rect.y + rect.height)
	{
		x = rect.x;
		while (x < rect.x + rect.width)
		{
			mlx_pixel_put_custom_portable(&mlx->img, x, y, rect.color);
			x++;
		}
		y++;
	}
	return (0);
}

int	render(t_data *mlx)
{
	t_img	*img;

	mlx->img.mlx_img = mlx_new_image(mlx->mlx_ptr, 
										MLX_WINDOW_WIDTH, MLX_WINDOW_HEIGHT);
	mlx->img.addr = mlx_get_data_addr(mlx->img.mlx_img, &mlx->img.bits_per_pixel,
										&mlx->img.line_length, &mlx->img.endian);
	img = &(mlx->img);
	if (mlx->win_ptr != NULL)
	{
		mlx_pixel_put_custom(img, 5, 5, GREEN_PIXEL);
		render_background(mlx, RED_PIXEL);
		render_rect(mlx, (t_rectangule){MLX_WINDOW_WIDTH - 100,
			MLX_WINDOW_HEIGHT - 100,100, 100, GREEN_PIXEL});
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->mlx_img, 0, 0);
	}
	return (0);
}
 