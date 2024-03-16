FUNCTION =  function/utils.c function/splitlines.c  function/joinstr.c  function/temp.c \
			function/parsing.c
FILE = so_long.c $(READ) $(FUNCTION)
BONUS = 

OBJFILE = $(FILE:%.c=%.o)
NAME = so_long

$(NAME): $(OBJFILE)
	cc -Wall -Wextra -Werror $(OBJFILE) -o $(NAME)


%.o: %.c mandatory/so_long.h readline/get_next_line.h
	cc -Wall -Wextra -Werror -o $@ -c $<

all : $(NAME)

clean:
	rm -f $(OBJFILE)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re