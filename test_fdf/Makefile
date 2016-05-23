# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbristhu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/25 16:40:21 by jbristhu          #+#    #+#              #
#    Updated: 2016/04/25 16:58:09 by jbristhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c

O = $(subst .c,.o,$(SRC))

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

.PHONY: clean fclean re all

$(NAME): fdf.h $(O)
	make -C libft/
	gcc $(FLAGS) -o $(NAME) $(O) -L libft/ -lft -lmlx -framework OpenGL \
		-framework AppKit

%.o: %.c fdf.h
	gcc $(FLAGS) -o $@ -c $<

clean:
	rm -f $(O)

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean
	
re: fclean all
