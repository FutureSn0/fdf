NAME = fdf.a

CC = gcc
AR = ar
CFLAGS = -Wextra -Wall -Werror
RM = rm -f

SRCS = ft_printf.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) -rcs $@ $?

%.o: %.c
	$(CC) $(CFLAGS) -I/aapryce/fdf/include -Iminilibx_linux -03 -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
