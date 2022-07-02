/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:48:13 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/02 04:48:19 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_STRUCTS_H
# define SHARED_STRUCTS_H

typedef struct s_coordinates
{
	int x;
	int y;
}	t_coordinates;

typedef struct s_map_dimensions
{
	int		rows;
	int 	columns;
	char	**map_matrix;
}	t_map_dimensions;

typedef struct s_valid_components
{
	int					count_exit;
	int					count_collectibles;
	int					count_internal_walls;
	int					count_floor;
	int					has_player_starting_position;
	int					has_valid_char;
	int					has_minimal_components;
	t_map_dimensions	map_dimensions;
	int					is_rect;
	int					is_surrounded_by_wall;
	int					is_valid_map;
}	t_valid_components;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_xmp_img
{
	t_coordinates	coordinates;
	t_coordinates	*coordinates_list;
	int				count;
	int				width;
	int				height;
	char			map_char;
	char			*relative_path;
	void 			*mlx_img;
}	t_xmp_img;

typedef struct s_game_play
{
	int	count_moves;
	int	count_collectibles_acquired;
	int	can_exit;
}	t_game_play;

typedef struct s_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_valid_components	map_components;
	t_game_play			game_play;
	t_xmp_img			img_wall;
	t_xmp_img			img_player;
	t_xmp_img			img_floor;
	t_xmp_img			img_exit;
	t_xmp_img			img_collectible;
	t_map_dimensions	map_dimensions;
}	t_data;

typedef struct s_rectangule
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rectangule;



#endif