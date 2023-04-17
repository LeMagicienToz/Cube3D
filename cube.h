/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:46:05 by muteza            #+#    #+#             */
/*   Updated: 2023/04/14 17:44:09 by muteza           ###   ########.fr       */
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

typedef struct s_raycas{
	int		dir_x;
	int		dir_y;
	double	raydir_x;
	double	raydir_y;
	double	plane_x;
	double	plane_y;
	int		cam_x;
	int		time;
	int		old_time;
}t_raycas;

typedef struct s_player{
	int	pos_x;
	int	pos_y;
}t_player;

typedef struct s_data{
	char		**map;
	int			key_code;
	t_mlx		mlx;
	t_player	player;
	t_raycas	raycas;
}t_data;

//parcing
void	check_pos(t_data *data);
void	parcing_map(int fd, t_data *data);

//LES MATH WHALHA
int		ray_casting(t_data *data);
void	ini_raycas(t_data *data);

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
int		ft_strlen_y(char **map);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);

#endif