/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_animation_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 02:56:48 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/14 04:37:46 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	animate_collectible(t_data *mlx)
{
	int		count_of_steps;
	char	*file_name;
	int		i;
	int		j;

	count_of_steps = 6;
	i = 0;
	j = 0;
	while (i < count_of_steps)
	{
		file_name =
			get_dynamic_img_name(IMG_ANIMATION_BASE_PATH, "collectible", i);
		j = 0;
		while (j < mlx->img_collectible.count)
		{
			if(mlx->img_collectible.coordinates_list[j].x == 0 && 
				mlx->img_collectible.coordinates_list[j].y == 0)
			{
				j++;
				continue;
			}
			if (mlx->img_player.coordinates.x == mlx->img_collectible.coordinates_list[j].x 
			&& mlx->img_player.coordinates.y == mlx->img_collectible.coordinates_list[j].y)
			{
				mlx->img_collectible.coordinates_list[j].x = 0;
				mlx->img_collectible.coordinates_list[j].y = 0;
				j++;
				continue;
			}
			coordinates_assign(&mlx->img_collectible.coordinates,
			mlx->img_collectible.coordinates_list[j].x,
			mlx->img_collectible.coordinates_list[j].y);
			image_change_file_path(mlx, &mlx->img_collectible, file_name);
			image_put(mlx, &mlx->img_collectible);
			j++;
		}
		free(file_name);
		file_name = NULL;
		i++;
	}
	return (0);
}
