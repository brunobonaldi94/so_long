/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_handler_bonus.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:32:20 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/15 04:58:02 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_EVENTS_HANDLER_BONUS_H
# define GAME_EVENTS_HANDLER_BONUS_H

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
void	put_moves_to_window(t_data *mlx, int moves);
int		animate_handler(t_data *mlx);
int		get_enemy_count(t_data *mlx);
#endif //GAME_EVENTS_HANDLER_BONUS_H