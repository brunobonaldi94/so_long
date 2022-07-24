/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:09:01 by bbonaldi          #+#    #+#             */
/*   Updated: 2022/07/23 16:43:25 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
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
# define GAME_NAME "so_long bbonaldi"
# define GAME_START_MESSAGE "Game has started!"

# define KEY_PRESS_EVENT 2
# define DESTROY_NOTIFY_EVENT 17

# define KEY_SCAPE 0xff1b
# define KEY_W 0x0077
# define KEY_A 0x0061
# define KEY_S 0x0073
# define KEY_D 0x0064
# define KEY_LEFT 0xFF51
# define KEY_UP 0xFF52
# define KEY_RIGHT 0xFF53
# define KEY_DOWN 0xFF54

# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFFFF

# define TRUE 1
# define FALSE 0

# define MAP_FLOOR_CHAR '0'
# define MAP_WALL_CHAR '1'
# define MAP_COLLECTIBLE_CHAR 'C'
# define MAP_EXIT_CHAR 'E'
# define MAP_PLAYER_CHAR 'P'

# define SUCCES_CODE 0
# define ERROR_CODE 1
# define MLX_ERROR 1
# define MLX_ERROR_MESSAGE "MLX Error: There was an error in Minilibx Library!"
# define FEW_ARGUMENTS_ERROR_MESSAGE "Too few arguments: You must run it \
with one map!"
# define TOO_MANY_ARGUMENTS_ERROR_MESSAGE "Too many arguments: You must \
run it with only one map!"
# define INVALID_MAP_ERROR_MESSAGE "Invalid Map"
# define NOT_FOUND_FILE_ERROR_MESSAGE "Map path location is not correct"
# define MAP_IS_NOT_RECT_ERROR_MESSAGE "Map is not a rectangule!"
# define MAP_HAS_INVALID_CHAR_ERROR_MESSAGE "Map has a invalid character. \
It's only allowed: 0 1 C E P!"
# define MAP_IS_NOT_SURROUNDED_BY_WALL_ERROR_MESSAGE "Map must be surrounded \
by wall."
# define MAP_MUST_HAVE_MINIMAL_COMPONENTS_ERROR_MESSAGE "Map must have at \
least one exit (E), one collectible (C) and one starting position (P)!"
# define WRONG_FILE_EXTENSION_ERROR_MESSAGE "Map must have .ber file extension"
# define MAP_HAS_MORE_PLAYER_ERROR_MESSAGE "Map cannot contain more than \
one player"
# define MAP_HAS_EMPTY_LINE_ERROR_MESSAGE "Map has an empty line!"

# define DEFAULT_PIXEL_SIZE	32
# define IMG_WALL_PATH "../assets/images/game/wall.xpm"
# define IMG_ENEMY_PATH "../assets/images/game/enemy.xpm"
# define IMG_COLLECTIBLE_PATH "../assets/images/game/collectable.xpm"
# define IMG_FLOOR_PATH "../assets/images/game/floor.xpm"
# define IMG_PLAYER_RIGHT_PATH "../assets/images/game/player_r.xpm"
# define IMG_PLAYER_LEFT_PATH "../assets/images/game/player_l.xpm"
# define IMG_EXIT_PATH "../assets/images/game/exit.xpm"
#endif // SO_LONG_H