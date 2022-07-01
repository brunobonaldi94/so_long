/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:06:09 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/01 23:30:21 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_RENDER_H
# define MAP_RENDER_H

void	map_render(t_data *mlx, t_map_dimensions *map_dimensions);
void	map_character_render(t_data *mlx, t_xmp_img *img,
			t_map_dimensions *map_dimensions);
#endif