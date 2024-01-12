SRC = input_validation.c main.c routine.c utils.c init.c actions.c

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