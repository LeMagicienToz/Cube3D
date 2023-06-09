# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uteza <uteza@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 13:40:09 by muteza            #+#    #+#              #
#    Updated: 2023/04/25 14:49:40 by uteza            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c\
		parcing/init_map.c\
		parcing/parcing_map.c\
		raycasting/ray_casting.c\
		raycasting/utils_raycas.c\
		put_img/put_img.c\
		raycasting/add_pos.c\
		raycasting/movement.c\
		utils/print_map.c\
		utils/ft_bzero.c\
		utils/ft_calloc.c\
		raycasting/movement_exec.c\
		utils/get_next_line.c\
		utils/get_next_line_utils.c\
		utils/ft_split.c\
		utils/ft_strlen_y.c\
		utils/ft_strdup.c\
		utils/ft_strlcpy.c\

OBJS	= ${SRCS:.c=.o}

NAME	= cube3d

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -g $< -o $@ -fsanitize=address

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	minilibx/libmlx.a
			$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -lz $(SRCS) -o $(NAME)

mlx:	
		curl https://raw.githubusercontent.com/Nimpoo/cub3d/dev/minilibx.tgz -o minilibx.tgz
		tar -xf minilibx.tgz
		rm minilibx.tgz
		make -C minilibx

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re :	fclean all

.PHONY: all clean fclean re mlx
