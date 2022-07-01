/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:36:33 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/01 23:50:18 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int init_mlx(t_data *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (exit_with_message(ERROR_CODE,
			MLX_ERROR_MESSAGE));
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
		mlx->map_dimensions.columns * DEFAULT_PIXEL_SIZE,
		mlx->map_dimensions.rows * DEFAULT_PIXEL_SIZE,
		"so_long bbonaldi");
	if (mlx->win_ptr == NULL)
	{
		free(mlx->win_ptr);
		return (exit_with_message(ERROR_CODE,
			MLX_ERROR_MESSAGE));
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data				mlx;
	char				*map_path;

	if (argc != 2)
	{
		if (argc <= 1)
			return (exit_with_message(ERROR_CODE,
						FEW_ARGUMENTS_ERROR_MESSAGE));
		return (exit_with_message(ERROR_CODE, 
					TOO_MANY_ARGUMENTS_ERROR_MESSAGE));
	}
	map_path = argv[1];
	mlx.map_dimensions = read_map(&mlx, map_path);
	if (!mlx.map_dimensions.map_matrix)
		return (exit_with_message(ERROR_CODE,
					INVALID_MAP_ERROR_MESSAGE));
	init_mlx(&mlx);
	map_characters_load(&mlx);
	map_render(&mlx, &mlx.map_dimensions);
	handle_events(&mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
