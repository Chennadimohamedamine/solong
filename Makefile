FUNCTION =  function/utils.c function/splitlines.c  function/joinstr.c  function/temp.c \
			function/parsing.c function/validgame.c function/drow.c function/hook_move.c \
			function/function_utils.c
FILE = so_long.c $(FUNCTION)
FILEBONUS =  bonus/so_long_bonus.c  function/utils.c function/splitlines.c  function/joinstr.c  function/temp.c \
			function/parsing.c function/validgame.c function/function_utils.c bonus/utils_bonus.c \
			bonus/utils.c function/hook_move.c 
			

OBJFILE = $(FILE:%.c=%.o)
OBJFILEBONUS = $(FILEBONUS:%.c=%.o)
NAME = so_long

%.o: %.c so_long.h bonus/so_long_bonus.h
	cc -Wall -Wextra -Werror -o $@ -c $<
$(NAME): $(OBJFILE)
	cc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit $(OBJFILE) -o $(NAME)



all : $(NAME)

bonus : $(OBJFILEBONUS)
	cc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit $(OBJFILEBONUS) -o so_long_bonus
clean:
	rm -f $(OBJFILE)
	rm -f $(OBJFILEBONUS)

fclean: clean
	rm -f $(NAME)
	rm -f so_long_bonus

re: fclean all

.PHONY: all clean fclean re