/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:36:33 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/01 04:11:15 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data				mlx;
	char				*map_path;

	if (argc != 2)
	{
		if (argc <= 1)
			return (print_error(FEW_ARGUMENTS_ERROR));
		return (print_error(TOO_MANY_ARGUMENTS_ERROR));
	}
	map_path = argv[1];
	mlx.map_dimensions = read_map(map_path);
	if (!mlx.map_dimensions.map_matrix)
		return (print_error(INVALID_MAP_ERROR));
	map_render(&mlx, &mlx.map_dimensions);
	handle_events(&mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
