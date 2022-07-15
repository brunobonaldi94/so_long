/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:50:46 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/15 03:44:23 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_xmp_img	image_init(char *file_path, char map_char, int count)
{
	t_xmp_img	img;

	img.height = 0;
	img.width = 0;
	img.count = count;
	img.is_right = TRUE;
	img.coordinates_list = NULL;
	img.relative_path = file_path;
	img.mlx_img = NULL;
	img.coordinates.x = 0;
	img.coordinates.y = 0;
	img.map_char = map_char;
	img.sprites_count = 0;
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

void	render_put_img_ptr(t_data *mlx, void **mlx_img,
			char *file_path, t_coordinates coordinates)
{
	int		width;
	int		height;

	if (mlx->win_ptr != NULL)
	{
		*mlx_img = mlx_xpm_file_to_image(mlx->mlx_ptr, file_path, &width,
				&height);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, *mlx_img,
			coordinates.x, coordinates.y);
	}
}
