NAME = fdf
LIBFT = libft/libft.a
MINILIBX = minilibx-linux/libmlx_Linux.a

CC = cc
CFLAGS = -Wextra -Wall -Werror
RM = rm -f

SRCS = fdf.c \
       get_next_line.c \
       get_next_line_utils.c \
       init_mlx.c \
       line_draw.c \
       map_draw.c \
       read_file.c \
       utills.c \
       colour.c \
       hooks.c \

OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) -lXext -lX11 -lm -lz -o $@ $(OBJ)

$(LIBFT):
	make -C libft

$(MINILIBX):
	make -C minilibx

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
