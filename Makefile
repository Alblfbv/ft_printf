# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfleury <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/04 12:25:31 by jfleury           #+#    #+#              #
#    Updated: 2019/01/16 13:54:04 by jfleury          ###   ########.fr        #
#    Updated: 2019/01/15 15:28:46 by allefebv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
AR = ar rc
RL = ranlib
CC = gcc
RM = rm -f
INCLUDE = ./include
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE) -c

SRC =		src/ft_printf.c 							\
			src/store/ft_struct_stock.c					\
			src/store/ft_struct_stock_2.c				\
			src/store/ft_struct_init_del.c				\
			src/process/conversion_id/process_c.c		\
			src/process/conversion_id/process_p.c		\
			src/process/conversion_id/process_s.c		\
			src/process/conversion_id/process_di.c		\
			src/process/conversion_id/process_id.c		\
			src/process/conversion_id/process_o.c		\
			src/process/conversion_id/process_u.c		\
			src/process/conversion_id/process_x.c		\
			src/process/conversion_id/process_xx.c		\
			src/process/conversion_id/process_f.c		\
			src/process/flags/process_flags.c			\
			src/process/flags/process_space.c			\
			src/process/flags/process_plus.c			\
			src/process/flags/process_zero.c			\
			src/process/flags/process_minus.c			\
			src/process/flags/process_hash.c			\
			src/process/min_width/process_min_width.c	\
			src/process/precision/process_preci_di.c	\
			src/process/precision/process_preci_s.c		\
			src/data/ft_data.c

SRC_LIB = 	src/libft/ft_isdigit.c 						\
			src/libft/ft_itoa.c							\
			src/libft/ft_itoa_base.c					\
			src/libft/ft_itoa_base_ll.c					\
			src/libft/ft_itoa_ll.c						\
			src/libft/ft_memalloc.c						\
			src/libft/ft_memmove.c						\
			src/libft/ft_memset.c						\
			src/libft/ft_putstr.c						\
			src/libft/ft_strcat.c						\
			src/libft/ft_strcpy.c						\
			src/libft/ft_strdup.c						\
			src/libft/ft_strextend.c					\
			src/libft/ft_strlen.c						\
			src/libft/ft_strncat.c						\
			src/libft/ft_strnchr.c						\
			src/libft/ft_strnew.c						\
			src/libft/ft_strextend.c					\
			src/libft/ft_strsub.c						\
			src/libft/ft_strupcase.c					

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(SRC_LIB)
	$(AR) $(NAME) *.o
	$(RL) $(NAME)
	echo "Make"

clean:
	$(RM) *.o
		echo "Make clean"

fclean: clean
	@$(RM) $(NAME)
		echo "Make fclean"

re: fclean all

.PHONY: all libft clean fclean re
.SILENT: $(NAME) clean fclean re all libft
