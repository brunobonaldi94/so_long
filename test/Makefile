NAME = so_long
NAME_BONUS = so_long_bonus
SO_LONG_PATH = ../
MAKE = make --no-print-directory
VALGRIND = valgrind -s --leak-check=full --show-leak-kinds=all --gen-suppressions=yes --verbose --log-fd=9 

all:	$(NAME)

MAP_FILE = ./assets/maps/giant_map.ber
#complex_map.ber  giant_map.ber  invalid_char_map.ber  no_collectible.ber  no_exit.ber  no_player.ber  not_rectangule.ber  not_surrounded_by_wall.ber  simple_map.ber  square_map.ber invalid_map.ber big.ber
NORMINETTES_PATH = $(shell find ../ -maxdepth 1 -type d ! -path '../.*' ! -path '../' ! -path '../test' ! -path '../utils' | grep -v mlx_linux | tr '\n' ' ')

$(NAME):
	@$(MAKE) all -C $(SO_LONG_PATH)

$(NAME_BONUS):
	@$(MAKE) bonus -C $(SO_LONG_PATH)

run:	$(NAME)
	cd ../ && $(VALGRIND) ./$(SO_LONG_PATH)$(NAME) $(MAP_FILE) 9>memcheck.log && cd ./test

run_bonus:	$(NAME_BONUS)
	cd ../ && $(VALGRIND) ./$(SO_LONG_PATH)$(NAME_BONUS) $(MAP_FILE) 9>memcheck.log && cd ./test

clean:
	@$(MAKE) clean -C $(SO_LONG_PATH) 

fclean:	clean
	@$(MAKE) fclean -C $(SO_LONG_PATH)

norm:
	norminette $(NORMINETTES_PATH) ../so_long.c

re:	fclean all

.PHONY: all clean fclean re