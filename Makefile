# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamedeir <mamedeir@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 18:37:44 by mamedeir          #+#    #+#              #
#    Updated: 2022/11/01 15:30:37 by mamedeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_print_functions.c ft_printf_utils.c

OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

all:	${NAME}
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS): $(SRC)
	cc $(CFLAGS) -c $(@:.o=.c)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

%.o: %.c
    cc $(FLAGS) -c $< -o $@
    ar rcs $(NAME) $@

.PHONY: all clean fclean re
