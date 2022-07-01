/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_structs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:48:13 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/01 01:17:44 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_STRUCTS_H
# define SHARED_STRUCTS_H

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
	int	x;
	int	y;
	int	width;
	int	height;
	char *relative_path;
	void *mlx_img;
}	t_xmp_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_xmp_img	img_wall;
	t_xmp_img	img_player;
	t_xmp_img	img_floor;
	t_xmp_img	img_exit;
	t_xmp_img	img_collectible;
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