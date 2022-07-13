/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_move_handler_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 23:46:09 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/12 23:54:20 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_image_number_file(t_data *mlx, char n)
{
	char	*image_number_file;
	char	n_string[2];
	char	*n_string_with_file_ext;

	n_string[0] = n;
	n_string[1] = '\0';
	n_string_with_file_ext = ft_strjoin(n_string, IMAGE_FILE_EXTENSION);
	image_number_file = ft_strjoin(IMG_NUMBER_BASE_PATH,
			n_string_with_file_ext);
	free(n_string_with_file_ext);
	image_change_file_path(mlx, &mlx->img_moves, image_number_file);
	image_put(mlx, &mlx->img_moves);
	free(image_number_file);
}

void	put_moves_to_window(t_data *mlx, int moves)
{
	char	*moves_to_string;
	size_t	i;

	moves_to_string = ft_itoa(moves);
	i = 0;
	while (moves_to_string[i])
	{
		coordinates_assign(&mlx->img_moves.coordinates, i * DEFAULT_PIXEL_SIZE,
			mlx->map_dimensions.rows * DEFAULT_PIXEL_SIZE);
		get_image_number_file(mlx, moves_to_string[i]);
		i++;
	}
	free(moves_to_string);
}
