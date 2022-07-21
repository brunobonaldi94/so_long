/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_animation_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 02:56:48 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/21 03:06:09 by bbonaldi         ###   ########.fr       */
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

void	move_enemy_and_check_game_over(t_data *mlx, t_coordinates c)
{
	put_enemy_in_map(mlx, c);
	if (mlx->map_dimensions.map_matrix[c.y][c.x - 1] == MAP_PLAYER_CHAR
		|| mlx->map_dimensions.map_matrix[c.y][c.x + 1] == MAP_PLAYER_CHAR)
		put_dead_player(mlx);
}

void	move_random_direction_enemy(t_data *mlx, int direction, t_coordinates c)
{
	if (direction == 1 && mlx->map_dimensions.map_matrix[c.y - 1][c.x]
		== MAP_FLOOR_CHAR)
	{
		move_enemy_and_check_game_over(mlx, (t_coordinates){c.x, c.y - 1});
		mlx->map_dimensions.map_matrix[c.y][c.x] = MAP_FLOOR_CHAR;
	}
	else if (direction == 2 && mlx->map_dimensions.map_matrix[c.y][c.x - 1]
		== MAP_FLOOR_CHAR)
	{
		move_enemy_and_check_game_over(mlx, (t_coordinates){c.x - 1, c.y});
		mlx->map_dimensions.map_matrix[c.y][c.x] = MAP_FLOOR_CHAR;
	}
	else if (direction == 3 && mlx->map_dimensions.map_matrix[c.y + 1][c.x]
		== MAP_FLOOR_CHAR)
	{
		move_enemy_and_check_game_over(mlx, (t_coordinates){c.x, c.y + 1});
		mlx->map_dimensions.map_matrix[c.y][c.x] = MAP_FLOOR_CHAR;
	}
	else if (direction == 4 && mlx->map_dimensions.map_matrix[c.y][c.x + 1]
		== MAP_FLOOR_CHAR)
	{
		move_enemy_and_check_game_over(mlx, (t_coordinates){c.x + 1, c.y});
		mlx->map_dimensions.map_matrix[c.y][c.x] = MAP_FLOOR_CHAR;
	}
}

int	move_enemy(t_data *mlx)
{
	int				i;
	t_coordinates	c;

	i = generate_random_int(0, mlx->img_enemy.count - 1);
	while (i < mlx->img_enemy.count)
	{
		coordinates_assign(&c, mlx->img_enemy.coordinates_list[i].x
			/ DEFAULT_PIXEL_SIZE, mlx->img_enemy.coordinates_list[i].y
			/ DEFAULT_PIXEL_SIZE);
		move_random_direction_enemy(mlx, generate_random_int(1, 4), c);
		i++;
	}
	return (0);
}

int	animate_handler(t_data *mlx)
{
	char	*file_name;

	add_delay(DEFAULT_DELAY);
	if (mlx->img_collectible.sprites_count == COLLECTIBLE_SPRITES_COUNT)
		mlx->img_collectible.sprites_count = 0;
	file_name = get_dynamic_img_name(IMG_ANIMATION_BASE_PATH, "collectible",
			mlx->img_collectible.sprites_count++);
	image_change_file_path(mlx, &mlx->img_collectible, file_name);
	move_enemy(mlx);
	map_re_render(mlx);
	free(file_name);
	return (0);
}
