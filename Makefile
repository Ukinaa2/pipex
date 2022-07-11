NAME		=	pipex

LIBFTPRINTF		=	libftprintf.a

LIBFTPRINTF_PATH	=	libftprintf/

SRC			=	pipex.c

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror -I.

RM			=	rm -f

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFTPRINTF_PATH)
	cc $(OBJ) $(LIBFTPRINTF_PATH)$(LIBFTPRINTF) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	make -C $(LIBFTPRINTF_PATH) clean
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	make -C $(LIBFTPRINTF_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
