# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 12:47:10 by anolivei          #+#    #+#              #
#    Updated: 2022/02/25 14:48:44 by anolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = labs_cli

SRCS = main.c ft_split.c ft_count_lines.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@gcc $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

run: all
	@./$(NAME)

.PHONY: all clean fclean re
