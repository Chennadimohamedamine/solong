FUNCTION =  function/utils.c function/splitlines.c  function/joinstr.c  function/temp.c \
			function/parsing.c function/validgame.c function/drow.c function/hook_move.c
FILE = so_long.c $(FUNCTION)
BONUS = 

OBJFILE = $(FILE:%.c=%.o)
NAME = so_long

$(NAME): $(OBJFILE)
	cc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit $(OBJFILE) -o $(NAME)


%.o: %.c so_long.h 
	cc -Wall -Wextra -Werror -o $@ -c $<

all : $(NAME)

clean:
	rm -f $(OBJFILE)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re