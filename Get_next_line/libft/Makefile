# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/23 17:43:40 by jbristhu          #+#    #+#              #
#    Updated: 2016/05/30 18:40:23 by jbristhu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_bzero.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c\
ft_memset.c ft_strcat.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c \
ft_strncat.c ft_strncpy.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isalnum.c ft_isdigit.c \
ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c\
ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
ft_strsplit.c ft_itoa.c ft_nbrlen.c ft_putchar.c ft_putstr.c ft_putendl.c \
ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
ft_abs.c free_and_join.c

O = $(subst .c,.o,$(SRCS))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

.PHONY: clean fclean all re

$(NAME): libft.h $(O)
	ar rc $(NAME) $(O)
	ranlib $(NAME)

%.o: %.c libft.h
	gcc $(FLAGS) -o $@ -c $<

clean:
	rm -f $(O)

fclean: clean
	rm -f $(NAME)

re: fclean all
