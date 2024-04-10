MANDATORY = 	mandatory/utils.c \ 
			mandatory/splitlines.c \ 
			mandatory/joinstr.c \ 
			mandatory/parsing.c \
			mandatory/validgame.c \
			mandatory/drow.c \
			mandatory/hook_move.c \
			mandatory/function_utils.c \
			mandatory/so_long.c


FILEBONUS = bonus/so_long_bonus.c \
			mandatory/splitlines.c \ 
			mandatory/joinstr.c \ 
			mandatory/parsing.c \
			mandatory/validgame.c \
			

OBJFILE      = $(MANDATORY:%.c=%.o)
OBJFILEBONUS = $(FILEBONUS:%.c=%.o)
NAME         = so_long

$(NAME) : $(OBJFILE)
	cc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit $(OBJFILE) -o $(NAME)


%.o : %.c so_long.h bonus/so_long_bonus.h
	cc -Wall -Wextra -Werror -o $@ -c $<

all   : $(NAME)
bonus : $(OBJFILEBONUS)
		cc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit $(OBJFILEBONUS) -o so_long_bonus
clean :
	rm -f $(OBJFILE)
	rm -f $(OBJFILEBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re