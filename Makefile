NAME = fract-ol

SRC = src/main.c src/newton.c src/color.c src/zoom.c src/key.c src/utils.c src/fractol_mandelbrot.c src/fractol_julia.c

INCLUDE = fractol.h minilibx-linux/libmlx.a libft/libft.a

FLAGS = -lX11 -lXext -lm -o ${NAME}

mlx:
	make -C ./minilibx-linux/

all: mlx
	cc ${SRC} ${INCLUDE} ${FLAGS}

clean: 
		rm src/*.o

fclean: clean
		rm ${NAME}

re: fclean all
