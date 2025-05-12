NAME = vector.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

INC =	vector.h			\

OBJDIR =	objdir

SRC = 	ft_init_vector.c	\
		ft_free_vector.c	\
		ft_realloc_vector.c	\
		ft_vector_addone.c	\

OBJ = $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ) $(INC) $(LIB)
	ar rcs $(NAME) $(LIB) $?

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

%.o : %.c Makefile $(INC) $(LIB)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ) $(OBJDIR)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all fclean re