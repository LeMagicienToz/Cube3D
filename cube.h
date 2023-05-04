/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelperrin <raphaelperrin@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:46:05 by muteza            #+#    #+#             */
/*   Updated: 2023/04/25 11:16:04 by raphaelperr      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
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

typedef struct s_utils
{
	int		max_j;
	int		max_i;
}	t_utils;

typedef struct s_data{
	char		**map;
	int			error;
	int			col;
	int			lin;
	int			i;
	int			j;
	char		c;
	int			good;
	t_utils		*u;
	t_mlx		mlx;
	t_player	player;
}t_data;

//parsing
void	check_pos(t_data *data);
int		parsing_map(char *name, t_data *data);
int		check_walls(t_data	*data);
int		parsing_name(char *str);
int		parsing_ext(char *str);
int		check_codec(char *name);
int		check_file(char *name);

//init_map
void	init_map(char *myfile, t_data *data);
void	init_map_string(char *myfile, t_data *data);
void	get_map(char *myfile, t_data *data);

//LES MATH WHALHA
void	ray_casting(t_data *data);

//mlx
void	put_img(t_data	*data);
void	make_img(t_data *data);

//movement
void	move_top(t_data *data);
int		hooks_player(int keycode, t_data *data);

//utils
void	print_map(char **str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *b, size_t n);
int		ft_strlen_y(char **map);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_strdup(const char *src);
#endif