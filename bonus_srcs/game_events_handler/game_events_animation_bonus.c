/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_animation_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 02:56:48 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/15 04:10:35 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	add_delay(int number_of_seconds)
{
	int	milli_seconds;
	clock_t start_time;

	milli_seconds = 1000 * number_of_seconds;
	start_time = clock();
	while (clock() < start_time + milli_seconds)
		;
} 

char	*get_dynamic_img_name(char *base_path, char *file_name, int index)
{
	char	*index_string;
	char	*file_name_index;
	char	*file_name_index_extension;
	char	*full_file_path;
	
	index_string = ft_itoa(index);
	file_name_index = ft_strjoin(file_name, index_string);
	file_name_index_extension = ft_strjoin(file_name_index,
		IMAGE_FILE_EXTENSION);
	full_file_path = ft_strjoin(base_path, file_name_index_extension);
	free(index_string);
	free(file_name_index);
	free(file_name_index_extension);
	return (full_file_path);
}

int	animate_handler(t_data *mlx)
{
	char *file_name;
	add_delay(DEFAULT_DELAY);
	if (mlx->img_collectible.sprites_count == COLLECTIBLE_SPRITES_COUNT)
		mlx->img_collectible.sprites_count = 0;
	file_name = get_dynamic_img_name(IMG_ANIMATION_BASE_PATH, "collectible", 
		mlx->img_collectible.sprites_count++);
	image_change_file_path(mlx, &mlx->img_collectible, file_name);
	map_re_render(mlx);
	free(file_name);
	return (0);
}