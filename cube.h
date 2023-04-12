/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muteza <muteza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 13:46:05 by muteza            #+#    #+#             */
/*   Updated: 2023/04/12 10:59:06 by muteza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

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

typedef struct s_data{
	char		**map;
	t_mlx		mlx;
	t_player	player;
}t_data;

//parcing
void	parcing_map(int fd, t_data *data);

//LES MATH WHALHA
void	ray_casting(t_data *data);

//mlx
void	make_img(t_data *data);

//utils
int		ft_strlen_y(char **map);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);

#endif