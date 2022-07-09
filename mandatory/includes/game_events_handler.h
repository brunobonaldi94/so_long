/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_handler.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:32:20 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/09 04:16:25 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_EVENTS_HANDLER_H
# define GAME_EVENTS_HANDLER_H

int		deal_key_press(int key, t_data *mlx);
int		deal_close(t_data *mlx);
void	handle_events(t_data *mlx);
void	destroy_display(t_data *mlx);
void	coordinates_assign(t_coordinates *coordinates, int x, int y);
void	calculate_new_coordinates(t_xmp_img *img,
			t_coordinates coordinates_adder);
int		is_there_an_object(t_data *mlx, t_xmp_img *img,
			t_coordinates coordinates_adder);
int		is_in_map_boundaries(t_data *mlx,
			t_coordinates coordinates_adder);
void	update_map_matrix(t_data *mlx, t_xmp_img *img);

#endif //GAME_EVENTS_HANDLER_H