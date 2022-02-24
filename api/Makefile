# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 12:47:10 by anolivei          #+#    #+#              #
#    Updated: 2022/02/24 16:57:11 by anolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = labs_api

LIBS = /usr/lib/

SRCS = main.c ulfius.c curl.c ft_strjoin.c

OBJS = $(SRCS:.c=.o)

# FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@gcc $(FLAGS) $(OBJS) -o $(NAME) -ljson-c -lcurl -lulfius

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@rm word.txt

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
