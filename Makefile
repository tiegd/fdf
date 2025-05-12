NAME = fdf

CC = cc

CFLAGS = -Wall -Wextra -Werror -MMD -MP -I$(INCLUDE) -I$(LIBFT) -I$(GNL) -I$(PRINTF) -I$(MLX) -I$(VECT) -g3

INCLUDE = inc

LIBFT = Libft

GNL = Libft/gnl

PRINTF = Libft/ft_printf

MLX = minilibx-linux

VECT = vector
			
BIN = bin/

DIR_SRC = src/

SRC = 	bresenham.c			\
		display.c			\
		handle_tab_utils.c	\
		handle_tab.c		\
		hook_fdf.c			\
		main.c				\
		parsing_utils.c		\
		parsing.c			\
		zoom.c				\
		zoom_utils.c		\
			
LIBS = 	vector/vector.a					\
		minilibx-linux/libmlx.a			\
		minilibx-linux/libmlx_Linux.a	\
		Libft/libft.a					\

OBJ = $(addprefix $(BIN), $(SRC:.c=.o))
DEPS =   $(OBJ:.o=.d)

all: .print_header $(BIN) libs $(NAME)

libs:
	$(MAKE) -s -C Libft
	$(MAKE) -s -C vector
	$(MAKE) -s -C minilibx-linux

$(NAME): $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS) -lm -lmlx -lXext -lX11 -L minilibx-linux

$(BIN)%.o: $(DIR_SRC)%.c | $(BIN)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN):
	mkdir -p $(BIN)

%.o : %.c Makefile $(LIBS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(MAKE) -s clean -C Libft
	$(MAKE) -s clean -C vector
	$(MAKE) -s clean -C minilibx-linux
	rm -rf $(BIN) Libft/fclean
	rm -rf $(BIN) vector/fclean

fclean: clean
	rm -f $(NAME) Libft/libft.a
	rm -f $(NAME) vector/vector.a

re: fclean all

.print_header:
	$(call DISPLAY_TITLE)

.PHONY: all clean fclean re libs

-include $(DEPS)

########################################################################################################################
#                                                       COLORS                                                         #
########################################################################################################################

DEF_COLOR 	= \033[0;39m
RED			= \033[0;91m
ORANGE		= \033[0;33m
YELLOW		= \033[1;93m
GREEN		= \033[1;92m
BLUE		= \033[0;94m
CYAN		= \033[0;96m
MAGENTA 	= \033[0;95m

########################################################################################################################
#                                                       DISPLAY                                                        #
########################################################################################################################

define DISPLAY_TITLE
						@echo "$(RED)     ### ###  ### ##   ### ###"
						@echo "$(ORANGE)     ##  ##   ##  ##   ##  ##"
						@echo "$(YELLOW)     ##       ##  ##   ##"
						@echo "$(GREEN)     ## ##    ##  ##   ## ##"
						@echo "$(BLUE)     ##       ##  ##   ##"
						@echo "$(CYAN)     ##       ##  ##   ##"
						@echo "$(MAGENTA)     ####     ### ##   ####$(DEF_COLOR)"
						@printf "\n"
endef