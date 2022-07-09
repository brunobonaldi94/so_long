/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:06:09 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/08 04:46:17 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_RENDER_H
# define MAP_RENDER_H

t_coordinates	save_coordinates(t_coordinates coordinates);
void			re_count_map_char(t_data *mlx);
int				map_render(t_data *mlx);
int				map_re_render(t_data *mlx);
void			map_character_render(t_data *mlx, t_xmp_img *img,
					t_map_dimensions *map_dimensions);
#endif