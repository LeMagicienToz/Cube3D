# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muteza <muteza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 13:40:09 by muteza            #+#    #+#              #
#    Updated: 2023/04/12 14:34:18 by muteza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c\
		parcing/parcing_map.c\
		raycasting/ray_casting.c\
		mlx/put_img.c\
		raycasting/add_pos.c\
		raycasting/movement.c\
		utils/get_next_line.c\
		utils/get_next_line_utils.c\
		utils/ft_split.c\
		utils/ft_strlen_y.c\
		utils/ft_strlcpy.c\

OBJS	= ${SRCS:.c=.o}

NAME	= cube3d

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -g $< -o $@ #-fsanitize=address

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf $$'\033[1m*'

$(NAME):
			$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -lz $(SRCS) -o $(NAME) 

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re :	fclean all

.PHONY: all clean fclean re