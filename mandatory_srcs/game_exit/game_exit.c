/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:34:31 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/20 03:09:59 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *message)
{
	ft_printf("%s\n%s\n", "Error", message);
}

void	print_map_error(t_data *mlx)
{
	ft_printf("Error\n");
	if (mlx->map_components.has_empty_line == TRUE)
		ft_printf("%s\n", MAP_HAS_EMPTY_LINE_ERROR_MESSAGE);
	if (mlx->map_components.is_rect == FALSE)
		ft_printf("%s\n", MAP_IS_NOT_RECT_ERROR_MESSAGE);
	if (mlx->map_components.has_minimal_components == FALSE)
		ft_printf("%s\n", MAP_MUST_HAVE_MINIMAL_COMPONENTS_ERROR_MESSAGE);
	if (mlx->map_components.has_valid_char == FALSE)
		ft_printf("%s\n", MAP_HAS_INVALID_CHAR_ERROR_MESSAGE);
	if (mlx->map_components.is_surrounded_by_wall == FALSE)
		ft_printf("%s\n", MAP_IS_NOT_SURROUNDED_BY_WALL_ERROR_MESSAGE);
	if (mlx->map_components.has_player_starting_position > 1)
		ft_printf("%s\n", MAP_HAS_MORE_PLAYER_ERROR_MESSAGE);
}

int	exit_with_message(int status_code, char *message)
{
	print_error(message);
	exit(status_code);
}

int	game_exit(t_data *mlx)
{
	destroy_images(mlx);
	destroy_map_matrix(&mlx->map_dimensions);
	destroy_window(mlx);
	destroy_display(mlx);
	exit(0);
	return (0);
}
