NAME		=	libftprintf.a

LIBFT		=	libft.a

LIBFT_PATH	=	libft/

SRC			=	ft_printf.c	ft_putunbr_fd.c	ft_puthex_fd.c

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror -I.

RM			=	rm -f

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

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
