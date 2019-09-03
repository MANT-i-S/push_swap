# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sholiak <sholiak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/29 17:03:46 by sholiak           #+#    #+#              #
#    Updated: 2019/09/03 16:35:58 by sholiak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

NAME2 = ./libft/libft.a

FILES = *.c

LIBFILES = ./libft/*.c

OBJ = *.o

LIBOBJ = ./libft/*.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(LIBFILES)
	ar rcs $(NAME) $(OBJ)
	gcc -Wall -Wextra -Werror push_swap.c better_sort.c sort_1_3.c sort_4_8.c operations.c tools.c tools_2.c tools_3.c libft.a -o push_swap
	gcc -Wall -Wextra -Werror checker.c dispatch.c operations.c tools.c tools_2.c tools_3.c libft.a -o checker
	
clean:
	rm -f $(OBJ) $(LIBOBJ)

fclean: clean
	rm -f $(NAME) $(NAME2)

re: fclean all
