NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

OBJECTS = $(SRCS:.c=.o)

SRCS = ft_printf.c \
		ft_helpers.c \
		ft_handles.c

LIBFTDIR=libft/
LIBFTA:=libft.a
LIBFT=$(LIBFTDIR)$(LIBFTA)

HEADER = $(LIBFTDIR)libft.h \
			ft_printf.h

INCLUDE=includes $(LIBFTDIR) .

all: $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)

$(NAME): $(LIBFT) $(OBJECTS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDE:%=-I%) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
