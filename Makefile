FLAG = -Wall -Werror -Wextra -g
IDIR = ./includes/
NAME = fdf
SRC_PATH = ./srcs/
LIB_PATH = ./libft/
LIB = libft/libft.a
MlX_PATH = ./mlx/
MLX = mlx/libmlx.a
M.FLAG = -Lmlx -lmlx -framework OpenGl -framework AppKit
CHEK = -fsanitize=address

FILES =	main.c				\
		read_file.c			

SRCS_FILES = $(addprefix srcs/, $(FILES))
OBJ = $(SRCS_FILES:.c=.o)

all:$(NAME)
$(NAME): $(LIB) $(OBJ)
	make -C $(MlX_PATH)
	gcc $(OBJ) $(LIB) -I $(LIB_PATH) $(M.FLAG) $(MLX) -I $(MlX_PATH) -o $(NAME) $(CHEK)

%.o: %.c
	gcc -c $(FLAG) $< -o $@ -I$(IDIR)

$(OBJ) : $(IDIR)fdf.h

clean:
	rm -f $(OBJ)
	make clean -C $(LIB_PATH)
	make clean -C $(MlX_PATH)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)
	rm -f $(MLX)

re: fclean all

libft/libft.a:
	make -C libft