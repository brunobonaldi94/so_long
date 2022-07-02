/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:09:01 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/01 23:25:29 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include "shared_structs.h"
# include "../libft/libft.h"
# include "map_validation.h"
# include "game_events_handler.h"
# include "map_render.h"
# include "game_exit.h"
# include "image_handler.h"

# define MLX_WINDOW_WIDTH 1280
# define MLX_WINDOW_HEIGHT 720

# define KEY_PRESS_EVENT 2
# define DESTROY_NOTIFY_EVENT 17

# define KEY_SCAPE 0xff1b
# define KEY_W 0x0077
# define KEY_A 0x0061
# define KEY_S 0x0073
# define KEY_D 0x0064
#define KEY_LEFT 0xFF51
#define KEY_UP 0xFF52
#define KEY_RIGHT 0xFF53
#define KEY_DOWN 0xFF54


# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

# define TRUE 1
# define FALSE 0

# define SUCCES_CODE 1
# define ERROR_CODE 1
# define MLX_ERROR 1
# define MLX_ERROR_MESSAGE "MLX Error: There was an error in Minilibx Library!"
# define FEW_ARGUMENTS_ERROR_MESSAGE "Too few arguments: You must run it\
with one map!"
# define TOO_MANY_ARGUMENTS_ERROR_MESSAGE "Too many arguments: You must \
run it with only one map!"
# define INVALID_MAP_ERROR_MESSAGE "Invalid Map"

# define DEFAULT_PIXEL_SIZE	32
# define IMG_WALL_PATH "../assets/images/wall.xpm"
# define IMG_ENEMY_PATH "../assets/images/enemy.xpm"
# define IMG_COLLECTIBLE_PATH "../assets/images/collectable.xpm"
# define IMG_FLOOR_PATH "../assets/images/floor.xpm"
# define IMG_PLAYER_PATH "../assets/images/player.xpm"
# define IMG_EXIT_PATH "../assets/images/exit.xpm"

#endif // SO_LONG_H