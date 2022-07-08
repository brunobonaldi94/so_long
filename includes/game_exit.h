/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 00:04:30 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/08 03:25:42 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_EXIT_H
# define GAME_EXIT_H

int		print_error(int error_number);
int		game_exit(t_data *mlx);
int		exit_with_message(int status_code, char *message);
void	destroy_window(t_data *mlx);
void	destroy_display(t_data *mlx);
void	free_coordinates(t_data *mlx);
void	destroy_images(t_data *mlx);
#endif