# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfleury <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/04 12:25:31 by jfleury           #+#    #+#              #
#    Updated: 2019/01/14 14:44:01 by allefebv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
CC = gcc
RM = rm -f
INCLUDE = ./Include
CFLAGS = -Wall -Wextra -g3 -I$(INCLUDE)
SRC =	src/ft_printf.c 							\
		src/store/ft_struct_stock.c					\
		src/store/ft_struct_stock_2.c				\
		src/store/ft_struct_init_del.c				\
		src/process/conversion_id/process_c.c		\
		src/process/conversion_id/process_p.c		\
		src/process/conversion_id/process_s.c		\
		src/process/conversion_id/process_di.c		\
		src/process/conversion_id/process_table.c	\
		src/process/flags/process_flags.c			\
		src/process/flags/process_hash.c			\
		src/process/flags/process_plus.c			\
		src/process/flags/process_zero.c			\
		src/process/flags/process_minus.c			\
		src/process/min_width/process_min_width.c	\
		src/process/precision/precision_di.c		\
		src/process/precision/precision_s.c			\
		src/data/ft_data.c

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
