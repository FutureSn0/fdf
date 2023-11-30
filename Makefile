NAME = fdf.a

CC = cc
AR = ar
CFLAGS = -Wextra -Wall -Werror
RM = rm -f

SRCS = fdf.c \

OBJS = $(SRCS:.c=.o)

INCLUDES = libft/libft.a minilibx-linux/libmlx-Linux.a

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/aapryce/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	$(AR) -rcs $@ $?

%.o: %.c
	$(CC) $(CFLAGS) -I/aapryce/fdf/include -Iminilibx-linux -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
