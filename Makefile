FUNCTION =  function/utils.c function/splitlines.c  function/joinstr.c  function/temp.c \
			function/parsing.c function/validgame.c function/drow.c function/hook_move.c
PRINTF = ft_printf/printhex.c  ft_printf/printdigit.c  ft_printf/printstr.c ft_printf/ft_printf.C
FILE = so_long.c $(FUNCTION) $(PRINTF)
BONUS = 

OBJFILE = $(FILE:%.c=%.o)
NAME = so_long

$(NAME): $(OBJFILE)
	cc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit $(OBJFILE) -o $(NAME)


%.o: %.c so_long.h  ft_printf/ft_printf.h
	cc -Wall -Wextra -Werror -o $@ -c $<

all : $(NAME)

clean:
	rm -f $(OBJFILE)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re