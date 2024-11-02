NAME	= so_long

SO_BONUS	= so_long_bonus

SRCS =	./src/get_next_line.c \
		./src/get_next_line_utils.c \
		./src/ft_print_error.c \
		./src/ft_map.c \
		./src/ft_map2.c \
		./src/ft_free.c \
		./src/ft_init_xpm.c \
		./src/ft_keypress.c \
		./src/ft_keypress2.c \
		./src/ft_addr.c \
		./src/ft_init.c \
		./src/main.c \
		./src/ft_putstr.c \
		./src/ft_putchar.c \



OBJS 		= ${SRCS:.c=.o}


PATH_MLX	= mlx
CCG			= gcc -g -fsanitize=address
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= so_long
FLAGS		= -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11 -Wl,-rpath=./bass/,-rpath=./mlx/,-rpath=./delay/

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			make -C $(PATH_MLX)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)



clean:
			make -C $(PATH_MLX) clean
			${RM} ${OBJS}
			${RM} ${OBJS_B}

fclean: 	clean
			make -C $(PATH_MLX) clean
			${RM} ${NAME}
			${RM} ${SO_BONUS}

re: 		fclean all

.PHONY:	 all clean fclean re
