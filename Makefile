NAME = libftprinft.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

OBJECTS = $(SRCS:.c=.o)

SRCS = ft_printf.c \

all: $(NAME)

NAME: $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
