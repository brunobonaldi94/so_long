/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:36:33 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/29 05:09:32 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_game(t_data *mlx)
{
	int		img_width;
	int		img_height;
	t_img	*img;
	char	*relative_path = "../assets/hero.xpm";

	img_height = 900;
	img_width = 900;
	img = &(mlx->img);
	if (mlx->win_ptr != NULL)
	{
 		mlx->img.mlx_img = mlx_xpm_file_to_image(mlx->mlx_ptr, relative_path, &img_width, &img_height);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->mlx_img, 0, 0);
		mlx_destroy_image(mlx->mlx_ptr, mlx->img.mlx_img);
	}
	return (0);
}

int	render_image(t_data *mlx, t_xmp_img *xmp_img)
{
	t_img	*img;

	img = &(mlx->img);
	if (mlx->win_ptr != NULL)
	{
 		mlx->img.mlx_img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			xmp_img->relative_path, &xmp_img->width, &xmp_img->height);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->mlx_img,
			xmp_img->x, xmp_img->y);
	}
	return (0);
}

void	print_map2(t_map_dimensions *map_dimensions, int is_valid_map)
{
	int j = 0;
	if (is_valid_map == FALSE)
		return ;
	while (j < map_dimensions->rows)
	{
		ft_printf("row:%d-%s\n", j, map_dimensions->map_matrix[j]);
		j++;
	}
}

int	main(int argc, char *argv[])
{
	t_data				mlx;
	t_map_dimensions	map_dimensions;
	int					is_valid_map;
	char				*file_path;

	if (argc <= 1)
		return (ERROR);
	file_path = argv[1];
	is_valid_map = read_map(file_path, &map_dimensions);
 	if (is_valid_map == FALSE)
		return (ERROR);
	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
		return (MLX_ERROR);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, MLX_WINDOW_WIDTH,
		MLX_WINDOW_HEIGHT, "so_long bbonaldi");
	if (mlx.win_ptr == NULL)
	{
		free(mlx.win_ptr);
		return (MLX_ERROR);
	}
	//handle_events(&mlx, &render_game);
	mlx_hook(mlx.win_ptr, KEY_PRESS_EVENT, (1L<<0), deal_key_press, &mlx);
	mlx_hook(mlx.win_ptr, DESTROY_NOTIFY_EVENT, (1L<<17), deal_close, &mlx);
	//mlx_loop_hook(mlx.mlx_ptr, render, &mlx);
	char *path = "../assets/hero.xpm";
	render_image(&mlx, &(t_xmp_img){0,0,0,0,path});
	mlx_loop(mlx.mlx_ptr);
  	return (0);
}