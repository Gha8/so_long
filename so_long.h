/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohamed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:16:15 by gmohamed          #+#    #+#             */
/*   Updated: 2024/11/01 22:16:27 by gmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1
# define TILE_SIZE 32

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "mlx/mlx.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win_mlx;
	int		window_width;
	int		window_height;
}				t_mlx;

typedef struct s_xpm
{
	void	*img;
	int		*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}				t_xpm;

typedef struct s_map
{
	char	**map_array;
	int		fd;
	int		fd2;
	int		num_rows;
	int		num_cols;
	int		num_player;
	int		num_collectible;
	int		num_exit;
	int		p_x;
	int		p_y;
	int		flag_exit;
}				t_map;

typedef struct s_info
{
	t_mlx	mlx;
	t_map	map;
	t_xpm	wall;
	t_xpm	floor;
	t_xpm	player;
	t_xpm	collectible;
	t_xpm	exit;
	t_xpm	player_exit;
	int		count_movement;
}				t_info;

void		ft_change_addr_player(t_info *all, int img_width, int img_height);
void		ft_change_addr_collect(t_info *all, int img_width, int img_height);
void		ft_change_addr_pl_ex(t_info *all, int img_width, int img_height);
void		ft_init(t_info *all);
void		ft_map_free(t_map *map);
void		ft_destroy(t_info *all);
void		ft_print_error2(char *str, t_map *map);
void		ft_player_move(t_info *all, char c);
int			keypress_event(int keycode, t_info *all);
int			keypress(t_info *all);
void		ft_init_xpm(t_info *all);
void		ft_map_wall(t_info *all);
int			ft_str_wall_col(t_info *all, int index);
int			ft_str_wall_row(char *str, int c);
void		ft_free(t_info *all);
void		ft_map(char *file_path, t_info *all);
void		ft_print_error(char *str);
int			ft_file_name(char *file_name, char *cmp);
int			ft_putchar(int c);
int			ft_putstr(char *s);
size_t		ft_strlen(const char *s);
int			ft_line(char *str, char **line, int ret);
char		*ft_rest(char *str);
char		*ft_read_line(char *str, int fd, int *ret);
int			get_next_line(int fd, char **line);
char		*ft_strdup(const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);

char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
