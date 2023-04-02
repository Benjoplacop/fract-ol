NAME = fract-ol

SRC = src/main.c src/burningship.c src/color.c src/zoom.c src/key.c src/utils.c src/fractol_mandelbrot.c src/fractol_julia.c

INCLUDE = fractol.h minilibx-linux/libmlx.a libft/libft.a

FLAGS = -lX11 -lXext -lm -o ${NAME}

OBJSRC = ${SRC:.c=.o}

mlx:
	make -C ./minilibx-linux/

all: mlx ${NAME}
	
${NAME}: ${OBJSRC}
		gcc ${OBJSRC} ${INCLUDE} ${FLAGS}

clean: 
		rm -f src/${OBJSRC}

fclean: clean
		rm -f ${NAME}

re: fclean all
