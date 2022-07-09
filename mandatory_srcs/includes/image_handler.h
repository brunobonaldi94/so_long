/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 01:03:40 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/02 19:05:29 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_HANDLER_H
# define IMAGE_HANDLER_H

void		image_render(t_data *mlx, t_xmp_img *img);
t_xmp_img	image_init(char *file_path, char map_char, int count);
void		image_put(t_data *mlx, t_xmp_img *img);
void		image_change_file_path(t_data *mlx, t_xmp_img *img,
				char *file_path);
void		map_characters_init(t_data *mlx);
void		map_characters_load(t_data *mlx);

#endif