/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 01:03:40 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/30 03:26:49 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_RENDER_H
# define IMAGE_RENDER_H

void		image_render(t_data *mlx, t_xmp_img *img);
void		image_destroy(t_data *mlx, t_xmp_img **img);
t_xmp_img	*image_init(char *file_path);
void		image_put(t_data *mlx, t_xmp_img *img);

#endif