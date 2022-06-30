/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:36:33 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/30 01:36:31 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	render_game(t_data *mlx)
// {
// 	int		img_width;
// 	int		img_height;
// 	t_img	*img;
// 	char	*relative_path = "../assets/hero.xpm";

// 	img_height = 900;
// 	img_width = 900;
// 	img = &(mlx->img);
// 	if (mlx->win_ptr != NULL)
// 	{
//  		mlx->img.mlx_img = mlx_xpm_file_to_image(mlx->mlx_ptr, relative_path, &img_width, &img_height);
// 		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->mlx_img, 0, 0);
// 		mlx_destroy_image(mlx->mlx_ptr, mlx->img.mlx_img);
// 	}
// 	return (0);
// }

// int	render_image(t_data *mlx)
// {
// 	t_img	*img;

// 	img = &(mlx->img);
// 	if (mlx->win_ptr != NULL)
// 	{
//  		mlx->img.mlx_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
// 			xmp_img->relative_path, &xmp_img->width, &xmp_img->height);
// 		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->mlx_img,
// 			xmp_img->x, xmp_img->y);
// 	}
// 	return (0);
// }

int	main(int argc, char *argv[])
{
	t_data				mlx;
	t_map_dimensions	*map_dimensions;
 	char				*map_path;

	if (argc <= 1)
		return (print_error(FEW_ARGUMENTS_ERROR));
	map_path = argv[1];
	map_dimensions = read_map(map_path);
 	if (!map_dimensions->map_matrix)
		return (print_error(INVALID_MAP_ERROR));
	map_render(&mlx, &map_dimensions);
	handle_events(&mlx);
	//char *path = "../assets/images/hero.xpm";
	//render_image(&mlx, &(t_xmp_img){0, 0, 0, 0, path});
	mlx_loop(mlx.mlx_ptr);
  	return (0);
}