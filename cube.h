/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rperrin <rperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:46:05 by muteza            #+#    #+#             */
/*   Updated: 2023/04/13 02:32:19 by rperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

typedef struct s_mlx{
	void	*mlx;
	int		width;
	int		height;
	void	*img;
	void	*mlx_win;
}t_mlx;

typedef struct s_player{
	int	pos_x;
	int	pos_y;
}t_player;

typedef struct s_utils{
	int	col;
	int	line;
	int	len;
	int	i;
	int	j;
}t_utils;

typedef struct s_data{
	char		**map;
	int			error;
	t_mlx		mlx;
	t_player	player;
	t_utils		u;
}t_data;

//parcing
void	check_pos(t_data *data);
void	parcing_map(char *name, t_data *data);

//LES MATH WHALHA
void	ray_casting(t_data *data);

//mlx
void	put_img(t_data	*data);
void	make_img(t_data *data);

//movement
void	move_top(t_data *data);
int		hooks_player(int keycode, t_data *data);

//utils
int		ft_strlen_y(char **map);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_strdup(const char *src);
#endif