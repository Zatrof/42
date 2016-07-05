# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/25 16:40:21 by jbristhu          #+#    #+#              #
#    Updated: 2016/06/15 17:50:01 by jbristhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c detect_opts.c stockdata.c sortfile.c print_and_destroy.c \
annexe_stockdata.c

O = $(subst .c,.o,$(SRC))

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

.PHONY: clean fclean re all

$(NAME): ft_ls.h $(O)
	make -C libft/
	gcc $(FLAGS) -o $(NAME) $(O) -L libft/ -lft

%.o: %.c fdf.h
	gcc $(FLAGS) -o $@ -c $<

clean:
	make -C libft/ clean
	rm -f $(O)

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
