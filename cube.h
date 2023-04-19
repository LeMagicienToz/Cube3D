/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:57:35 by muteza            #+#    #+#             */
/*   Updated: 2023/04/19 15:36:52 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include "mlx/minilibx/mlx.h"
# include <math.h>

# define KEYPRESS 2
# define KEYRELEASE 3
# define KEYQUIT 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_RIGHT 124

typedef struct s_mlx{
	void	*mlx;
	int		width;
	int		height;
	void	*img;
	void	*mlx_win;
}t_mlx;

typedef struct s_vec{
	double	x;
	double	y;
}t_vec;

typedef struct s_raycas{
	int		dir_x;
	int		dir_y;
	t_vec	map;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	t_vec	ray_dir;
	t_vec	plane;
	double	dist_perp;
	int		cam_x;
	int		time;
	t_vec	delta_dist;
	t_vec	side_dist;
	int		old_time;

}t_raycas;

typedef struct s_player{
	double	pos_x;
	double	pos_y;
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
	// t_value		flor;
	// t_value		sky;
	char		c;
	t_utils		*u;
	int			key_code;
	t_mlx		mlx;
	t_player	player;
	t_raycas	raycas;
}t_data;

//parcing
void	check_pos(t_data *data);
void	parcing_map(char *name, t_data *data);
int		check_walls(t_data	*data);

//init_map
void	init_map(char *myfile, t_data *data);
void	init_map_string(char *myfile, t_data *data);
void	get_map(char *myfile, t_data *data);

//LES MATH WHALHA
int		ray_casting(t_data *data);
void	ini_raycas(t_data *data);
void	dir_ray(t_data *data);

//mlx
int		exit_esc(t_data *data);
void	put_img(t_data	*data);
void	make_img(t_data *data);

//movement
void	move_right(t_data *data);
void	move_left(t_data *data);
void	move_back(t_data *data);
void	check_all_movement(t_data *data);
int		key_press_code(int key, t_data *data);
void	move_foward(t_data *data);
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