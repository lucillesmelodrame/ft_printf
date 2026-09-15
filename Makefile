NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

OBJECTS = $(SRCS:.c=.o)

SRCS = ft_printf.c \
		ft_helpers.c \
		ft_handles.c \

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
