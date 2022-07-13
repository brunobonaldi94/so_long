MANDATORY_PATH = ./mandatory_srcs
MAP_VALIDATION_PATH = $(addprefix $(MANDATORY_PATH)/, map_validation)
GAME_EVENTS_HANDLER_PATH = $(addprefix $(MANDATORY_PATH)/, game_events_handler)
GAME_EXIT_PATH = $(addprefix $(MANDATORY_PATH)/, game_exit)
MAP_RENDER_PATH = $(addprefix $(MANDATORY_PATH)/, map_render)
IMAGE_RENDER_PATH = $(addprefix $(MANDATORY_PATH)/, image_handler)

SRCS =	so_long.c \
		$(addprefix $(MAP_VALIDATION_PATH)/,	map_validation.c map_validation_helpers.c \
													map_validation_checkers.c map_validation_helpers_II.c) \
		$(addprefix $(GAME_EVENTS_HANDLER_PATH)/, game_events_handler.c game_events_utils.c) \
		$(addprefix $(MAP_RENDER_PATH)/, map_render.c map_render_utils.c) \
		$(addprefix $(GAME_EXIT_PATH)/, game_exit.c game_exit_utils.c) \
		$(addprefix $(IMAGE_RENDER_PATH)/, image_handler.c image_handler_utils.c)

OBJS = $(SRCS:.c=.o)

BONUS_PATH = ./bonus_srcs
MAP_VALIDATION_BONUS_PATH = $(subst $(MANDATORY_PATH), $(BONUS_PATH), $(MAP_VALIDATION_PATH))
GAME_EVENTS_HANDLER_BONUS_PATH = $(subst $(MANDATORY_PATH), $(BONUS_PATH), $(GAME_EVENTS_HANDLER_PATH))
MAP_RENDER_BONUS_PATH = $(subst $(MANDATORY_PATH), $(BONUS_PATH), $(MAP_RENDER_PATH))
IMAGE_RENDER_BONUS_PATH = $(subst $(MANDATORY_PATH), $(BONUS_PATH), $(IMAGE_RENDER_PATH))
GAME_EXIT_BONUS_PATH = $(subst $(MANDATORY_PATH), $(BONUS_PATH), $(GAME_EXIT_PATH))

SRCS_BONUS = 	so_long_bonus.c \
		$(addprefix $(MAP_VALIDATION_BONUS_PATH)/,	map_validation_bonus.c map_validation_helpers_bonus.c \
													map_validation_checkers_bonus.c map_validation_helpers_II_bonus.c) \
		$(addprefix $(GAME_EVENTS_HANDLER_BONUS_PATH)/, game_events_handler_bonus.c game_events_utils_bonus.c game_events_move_handler_bonus.c) \
		$(addprefix $(MAP_RENDER_BONUS_PATH)/, map_render_bonus.c map_render_utils_bonus.c) \
		$(addprefix $(GAME_EXIT_BONUS_PATH)/, game_exit_bonus.c game_exit_utils_bonus.c) \
		$(addprefix $(IMAGE_RENDER_BONUS_PATH)/, image_handler_bonus.c image_handler_utils_bonus.c)


OBJS_BONUS = $(SRCS_BONUS:.c=.o)

SRCS_LIBFT_PATH = ./libft/
LIBFT = libft.a
LIBFT_FULL_PATH = $(addprefix $(SRCS_LIBFT_PATH),$(LIBFT))

MLX_LINUX_PATH = ./mlx_linux/
MLX = libmlx_Linux.a
MLX_FULL_PATH = $(addprefix $(MLX_LINUX_PATH),$(MLX))

NAME = so_long
INCLUDES_MLX_LINUX = -Imlx_linux
INCLUDES_USR = -I./usr/include
INCLUDES = -I$(SRCS_LIBFT_PATH)includes -I$(SRCS_LIBFT_PATH) -I$(addprefix $(MANDATORY_PATH)/, includes)

NAME_BONUS = so_long_bonus
INCLUDES_BONUS = -I$(SRCS_LIBFT_PATH)includes -I$(SRCS_LIBFT_PATH) -I$(addprefix $(BONUS_PATH)/, includes)

LIBRARY_MLX_PATH = -Lmlx_linux -lmlx_Linux -L/usr/lib
LIBRARIES_MLX = -lXext -lX11 -lm -lz

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

%.o:	%.c
	$(CC) $(CFLAGS) $(INCLUDES_MLX_LINUX) $(INCLUDES_USR) $(INCLUDES) -O3 -c $< -o $@

%_bonus.o:	%_bonus.c
	$(CC) $(CFLAGS) $(INCLUDES_MLX_LINUX) $(INCLUDES_USR) $(INCLUDES_BONUS) -O3 -c $< -o $@

all:	$(LIBFT_FULL_PATH) $(MLX_FULL_PATH) $(NAME)

bonus:	$(LIBFT_FULL_PATH) $(MLX_FULL_PATH) $(NAME_BONUS)

$(LIBFT_FULL_PATH):
	make bonus -C $(SRCS_LIBFT_PATH)
	cp $(LIBFT_FULL_PATH) ./

$(MLX_FULL_PATH):
	@tput setaf 5
	@echo COMPILING MLX
	@cd $(MLX_LINUX_PATH) && ./configure && cd ../
	@cp $(MLX_FULL_PATH) ./

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBRARY_MLX_PATH) \
	$(INCLUDES_MLX_LINUX) $(LIBRARIES_MLX) $(LIBFT) -o $(NAME)

$(NAME_BONUS):	$(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBRARY_MLX_PATH) \
	$(INCLUDES_MLX_LINUX) $(LIBRARIES_MLX) $(LIBFT) -o $(NAME_BONUS)

clean:
	make clean -C $(SRCS_LIBFT_PATH)
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:	clean
	make fclean -C $(SRCS_LIBFT_PATH)
	$(RM) $(NAME) $(NAME_BONUS) $(LIBFT) $(MLX)

re:	fclean all

.PHONY:	all clean fclean re