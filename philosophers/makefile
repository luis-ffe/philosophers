# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 20:03:54 by luis-ffe          #+#    #+#              #
#    Updated: 2024/01/15 20:03:56 by luis-ffe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = input_validation.c main.c routine.c utils.c init.c actions.c actions_utils.c

OBJ = $(SRC:.c=.o)

CFLAGS = -pthread -Wall -Werror -Wextra -fsanitize=thread

CC = cc

RM = rm -f

NAME = philo

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all