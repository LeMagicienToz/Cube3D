# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 13:40:09 by muteza            #+#    #+#              #
#    Updated: 2023/05/16 21:51:50 by raphaelperr      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c\
		parsing/init_map.c\
		parsing/check_walls.c\
		parsing/check_args.c\
		parsing/check_all.c\
		parsing/get_info.c\
		parsing/get_info_norm.c\
		parsing/check_info.c\
		parsing/remove_info.c\
		utils/ft_strcmp_r.c\
		utils/print_map.c\
		utils/ft_bzero.c\
		utils/ft_calloc.c\
		utils/ft_split.c\
		utils/ft_strlen_y.c\
		utils/ft_strdup.c\
		utils/ft_strlcpy.c\
		utils/ft_strncmp.c\
		utils/ft_strchr.c\
		utils/ft_atoi.c\
		utils/ft_isdigit.c\
		utils/ft_strlen.c\

OBJS	= ${SRCS:.c=.o}

NAME	= cube3d

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -g $< -o $@ -fsanitize=address

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf $$'\033[1m*'

$(NAME):
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re :	fclean all

.PHONY: all clean fclean re
