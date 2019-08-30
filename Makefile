# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/29 17:03:46 by sholiak           #+#    #+#              #
#    Updated: 2019/08/29 21:27:40 by sholiak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpush.a

NAME2 = ./libft/libft.a

FILES = *.c

LIBFILES = ./libft/*.c

OBJ = *.o

LIBOBJ = ./libft/*.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(FILES) $(LIBFILES)
	ar rcs $(NAME) $(OBJ)
	gcc -Wall -Wextra -Werror push_swap.c libpush.a -o push_swap -g
	gcc -Wall -Wextra -Werror checker.c libpush.a -o checker -g
	
clean:
	rm -f $(OBJ) $(LIBOBJ)

fclean: clean
	rm -f $(NAME) $(NAME2)

re: fclean all
