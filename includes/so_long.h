/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:09:01 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/06/25 16:17:03 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
#include <fcntl.h>
# include "shared_structs.h"
# include "../libft/libft.h"
# include "map_validation.h"
# include "events_handler.h"

# define MLX_WINDOW_WIDTH 1280
# define MLX_WINDOW_HEIGHT 720
# define MLX_ERROR 1
# define ERROR 1

# define KEY_PRESS_EVENT 2
# define DESTROY_NOTIFY_EVENT 17

# define KEY_SCAPE 0xff1b
# define KEY_W 0x0077
# define KEY_A 0x0061
# define KEY_S 0x0073
# define KEY_D 0x0064

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

# define TRUE 1
# define FALSE 0

int	render(t_data *mlx);

#endif // SO_LONG_H