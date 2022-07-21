NAME		=	pipex

LIBFT		=	libft.a

LIBFT_PATH	=	libft/

SRC			=	pipex.c errors_case.c

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror -I.

RM			=	rm -f

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	cc $(OBJ) $(LIBFT_PATH)$(LIBFT) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
