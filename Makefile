# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfleury <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/04 12:25:31 by jfleury           #+#    #+#              #
#    Updated: 2019/01/04 12:29:03 by jfleury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c

LIB = libft/libft.a
OBJ = $(SRC:.c=.o)

all: $(NAME)

libft:
	make -C libft/

$(NAME): $(OBJ) libft
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIB)
		echo "Make ok !"

clean:
	$(RM) $(OBJ)
		make -C libft/ clean
		echo "Make clean ok !"

fclean: clean
	@$(RM) $(NAME)
		make -C libft/ fclean
		echo "Make fclean ok !"

re: fclean all

.PHONY: all libft clean fclean re
.SILENT: $(NAME) clean fclean re all libft
