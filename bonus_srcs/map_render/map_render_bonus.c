/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:25:06 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/20 01:51:44 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_footer(t_data *mlx)
{
	int		j;
	void	*mlx_move_img;
	int		offset;

	j = 0;
	mlx_move_img = NULL;
	render_put_img_ptr(mlx, &mlx_move_img, IMG_MOVES_PATH,
		(t_coordinates){j++, mlx->map_dimensions.rows * DEFAULT_PIXEL_SIZE});
	offset = ft_get_nbr_elements(mlx->game_play.count_moves, 10);
	while ((j + offset) < mlx->map_dimensions.columns)
	{
		coordinates_assign(&mlx->img_footer.coordinates,
			(j + offset) * DEFAULT_PIXEL_SIZE,
			mlx->map_dimensions.rows * DEFAULT_PIXEL_SIZE);
		image_put(mlx, &mlx->img_footer);
		j++;
	}
	put_moves_to_window(mlx, mlx->game_play.count_moves);
	if (mlx->win_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx_move_img);
}

void	render_map_component(t_data *mlx, t_xmp_img *img,
			t_map_dimensions *map_dimensions)
{
	t_coordinates	counters;
	int				count;

	counters.y = 0;
	count = 0;
	img->coordinates_list = (t_coordinates *)malloc(sizeof(t_coordinates)
			* img->count);
	while (counters.y < map_dimensions->rows)
	{
		counters.x = 0;
		while (counters.x < map_dimensions->columns)
		{
			if (map_dimensions->map_matrix[counters.y][counters.x]
					== img->map_char)
			{
				img->coordinates.x = (counters.x * DEFAULT_PIXEL_SIZE);
				img->coordinates.y = (counters.y * DEFAULT_PIXEL_SIZE);
				image_put(mlx, img);
				img->coordinates_list[count++]
					= save_coordinates(img->coordinates);
			}
			counters.x++;
		}
		counters.y++;
	}
}

int	map_render(t_data *mlx)
{
	render_map_component(mlx, &mlx->img_wall, &mlx->map_dimensions);
	render_map_component(mlx, &mlx->img_floor, &mlx->map_dimensions);
	render_map_component(mlx, &mlx->img_player, &mlx->map_dimensions);
	render_map_component(mlx, &mlx->img_collectible, &mlx->map_dimensions);
	render_map_component(mlx, &mlx->img_exit, &mlx->map_dimensions);
	render_map_component(mlx, &mlx->img_enemy, &mlx->map_dimensions);
	render_footer(mlx);
	return (0);
}

int	map_re_render(t_data *mlx)
{	
	re_count_map_char(mlx);
	free_coordinates(mlx);
	map_render(mlx);
	return (0);
}
