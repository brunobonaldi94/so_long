/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:59:57 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/30 03:28:53 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_xmp_img	*image_init(char *file_path)
{
	t_xmp_img *img;
	
	img = (t_xmp_img *)malloc(sizeof(t_xmp_img));
	img->height = 0;
	img->width = 0;
	img->relative_path = file_path;
	img->mlx_img = NULL;
	img->x = 0;
	img->y = 0;
	return (img);
}

void	image_destroy(t_data *mlx, t_xmp_img **img)
{
	mlx_destroy_image(mlx->mlx_ptr, (*img)->mlx_img);
	free(*img);
	*img = NULL;
}

void	image_render(t_data *mlx, t_xmp_img *img)
{
	if (mlx->win_ptr != NULL)
	{
 		img->mlx_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			img->relative_path, &img->width, &img->height);
	}
}

void	image_put(t_data *mlx, t_xmp_img *img)
{
	if (mlx->win_ptr != NULL)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->mlx_img,
			img->x, img->y);
	}
}