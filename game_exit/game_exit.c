/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:34:31 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/01 02:05:32 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(int error_number)
{
	if (error_number == MLX_ERROR)
		ft_printf(MLX_ERROR_MESSAGE);
	else if (error_number == FEW_ARGUMENTS_ERROR)
		ft_printf(FEW_ARGUMENTS_ERROR_MESSAGE);
	else if (error_number == TOO_MANY_ARGUMENTS_ERROR)
		ft_printf(TOO_MANY_ARGUMENTS_ERROR_MESSAGE);
	else if (error_number == INVALID_MAP_ERROR)
		ft_printf(INVALID_MAP_ERROR_MESSAGE);
	return (ERROR_CODE);
}

void	game_exit(t_data *mlx, t_map_dimensions *map_dimensions)
{
	deal_close(mlx);
	destroy_map_matrix(map_dimensions);
}


