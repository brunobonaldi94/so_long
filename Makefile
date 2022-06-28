MAP_VALIDATION_PATH = ./map_validation
EVENTS_HANDLER_PATH = ./events_handler
UTILS_PATH = ./utils
SRCS =	so_long.c \
		$(addprefix $(MAP_VALIDATION_PATH)/,	map_validation.c map_validation_helpers.c \
													map_validation_checkers.c) \
		$(addprefix $(EVENTS_HANDLER_PATH)/, events_handler.c) \
		$(addprefix $(UTILS_PATH)/, render.c)

OBJS = $(SRCS:.c=.o)

SRCS_LIBFT_PATH = ./libft/
LIBFT = libft.a
LIBFT_FULL_PATH = $(addprefix $(SRCS_LIBFT_PATH),$(LIBFT))

NAME = so_long
INCLUDES_MLX_LINUX = -Imlx_linux
INCLUDES_USR = -I./usr/include
INCLUDES = -I$(SRCS_LIBFT_PATH)includes -I$(SRCS_LIBFT_PATH) -I./includes

LIBRARY_MLX_PATH = -Lmlx_linux -lmlx_Linux -L/usr/lib
LIBRARIES_MLX = -lXext -lX11 -lm -lz

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

%.o:	%.c
	$(CC) $(CFLAGS) $(INCLUDES_MLX_LINUX) $(INCLUDES_USR) $(INCLUDES) -O3 -c $< -o $@

all:	$(LIBFT_FULL_PATH) $(NAME)	

$(LIBFT_FULL_PATH):
	make bonus -C $(SRCS_LIBFT_PATH)
	cp $(LIBFT_FULL_PATH) ./

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBRARY_MLX_PATH) \
	$(INCLUDES_MLX_LINUX) $(LIBRARIES_MLX) $(LIBFT) -o $(NAME)

clean:
	make clean -C $(SRCS_LIBFT_PATH)
	$(RM) $(OBJS) $(LIBFT)

fclean:	clean
	make fclean -C $(SRCS_LIBFT_PATH)
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re