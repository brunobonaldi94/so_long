/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:50:46 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/21 00:03:09 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_xmp_img	image_init(char *file_path, char map_char, int count)
{
	t_xmp_img	img;

	img.height = 0;
	img.width = 0;
	img.count = count;
	img.is_right = TRUE;
	img.relative_path = file_path;
	img.mlx_img = NULL;
	img.coordinates.x = 0;
	img.coordinates.y = 0;
	img.map_char = map_char;
	return (img);
}

void	image_change_file_path(t_data *mlx, t_xmp_img *img, char *file_path)
{
	mlx_destroy_image(mlx->mlx_ptr, img->mlx_img);
	img->relative_path = file_path;
	image_render(mlx, img);
}

void	image_render(t_data *mlx, t_xmp_img *img)
{
	if (mlx->win_ptr != NULL)
	{
		img->mlx_img = mlx_xpm_file_to_image(mlx->mlx_ptr, img->relative_path,
				&img->width, &img->height);
	}
}

void	image_put(t_data *mlx, t_xmp_img *img)
{
	if (mlx->win_ptr != NULL)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->mlx_img,
			img->coordinates.x, img->coordinates.y);
	}
}
