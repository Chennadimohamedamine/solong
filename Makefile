MANDATORY = mandatory/utils.c \
            mandatory/splitlines.c \
            mandatory/joinstr.c \
            mandatory/parsing.c \
            mandatory/validgame.c \
            mandatory/drow.c \
            mandatory/drow_.c \
            mandatory/hook_move.c \
            mandatory/so_long.c \

FILEBONUS = bonus/so_long_bonus.c \
            bonus/splitlines_bonus.c \
            bonus/joinstr_bonus.c \
            bonus/parsing_bonus.c \
            bonus/validgame_bonus.c \
			bonus/utils_bonus.c \
			bonus/function_utils.c \
			bonus/game_bonus.c \
			bonus/ft_itoa_bonus.c \
			bonus/move_hooks_bonus.c \
			bonus/movehooks_bonus.c \
			bonus/move_enamy.c \
			bonus/function_enmy.c \
			
OBJFILE = $(MANDATORY:%.c=%.o)
OBJFILEBONUS = $(FILEBONUS:%.c=%.o)
NAME = so_long

$(NAME): $(OBJFILE)
	cc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -fsanitize=address $(OBJFILE) -o $(NAME)

%.o: %.c mandatory/so_long.h bonus/so_long_bonus.h
	cc -Wall -Wextra -Werror -o $@ -c $<

all: $(NAME)

bonus: $(OBJFILEBONUS)
	cc -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -fsanitize=address $(OBJFILEBONUS) -o so_long_bonus

clean:
	rm -f $(OBJFILE)
	rm -f $(OBJFILEBONUS)

fclean: clean
	rm -f $(NAME)
	rm -f so_long_bonus

re: fclean all

.PHONY: all clean fclean re