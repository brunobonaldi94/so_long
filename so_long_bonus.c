/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:36:33 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/23 16:44:09 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	init_mlx(t_data *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (exit_with_message(ERROR_CODE, MLX_ERROR_MESSAGE));
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->map_dimensions.columns
			* DEFAULT_PIXEL_SIZE, (mlx->map_dimensions.rows + 1)
			* DEFAULT_PIXEL_SIZE,
			GAME_NAME);
	if (mlx->win_ptr == NULL)
	{
		free(mlx->win_ptr);
		return (exit_with_message(ERROR_CODE, MLX_ERROR_MESSAGE));
	}
	ft_printf(GAME_START_MESSAGE);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	mlx;
	char	*map_path;

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
	{
		print_map_error(&mlx);
		return (ERROR_CODE);
	}
	init_mlx(&mlx);
	map_characters_load(&mlx);
	map_render(&mlx);
	handle_events(&mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
