/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohamed <gmohamed@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-01 21:25:09 by gmohamed          #+#    #+#             */
/*   Updated: 2024-11-01 21:25:09 by gmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_row_col(t_info *all)
{
	char	*line;
	int		rd;
	int		count;
	int		flag;

	flag = 0;
	count = 0;
	rd = get_next_line(all->map.fd, &line);
	all->map.num_cols = (int)ft_strlen(line);
	while (rd > 0)
	{
		if (all->map.num_cols != (int)ft_strlen(line))
			flag = 1;
		free(line);
		rd = get_next_line(all->map.fd, &line);
		count++;
	}
	free(line);
	all->map.num_rows = count;
	if (flag == 1)
		return (0);
	return (1);
}

void	ft_map_array(t_info *all)
{
	int		num_rows;
	int		i;
	char	*line;
	int		rd;

	i = 0;
	num_rows = all->map.num_rows;
	all->map.map_array = (char **)malloc(sizeof(char *) * (num_rows + 1));
	if (!all->map.map_array)
		return ;
	all->map.map_array[num_rows] = '\0';
	rd = get_next_line(all->map.fd2, &line);
	while (rd > 0)
	{
		all->map.map_array[i++] = ft_strdup(line);
		free(line);
		rd = get_next_line(all->map.fd2, &line);
	}
	free(line);
}

void	ft_map_init(t_map *map, char c, int i, int j)
{
	if (c == 'P')
	{
		map->p_x = i;
		map->p_y = j;
		map->num_player += 1;
	}
	else if (c == 'C')
		map->num_collectible += 1;
	else if (c == 'E')
		map->num_exit += 1;
	else if (c == 'k')
	{
		if (map->num_collectible == 0)
			ft_print_error2("Error:\nNo collectible", map);
		else if (map->num_player != 1)
			ft_print_error2("Error:\nPlayer must be one", map);
		else if (map->num_exit == 0)
			ft_print_error2("Error:\nNo Exit", map);
	}
}

void	ft_map_element(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->num_player = 0;
	map->num_collectible = 0;
	map->num_exit = 0;
	map->flag_exit = 0;
	while (map->map_array[i])
	{
		j = 0;
		while (map->map_array[i][j])
		{
			if (!ft_strchr("10PCE", map->map_array[i][j]))
				ft_print_error2("Error:\nPas de 10EPC", map);
			ft_map_init(map, map->map_array[i][j], i, j);
			j++;
		}
		i++;
	}
	ft_map_init(map, 'k', i, j);
}

void	ft_map(char *filename, t_info *all)
{
	all->map.fd = open(filename, O_RDONLY);
	if (all->map.fd == -1)
		ft_print_error("Error:\nFile open error.");
	all->map.fd2 = open(filename, O_RDONLY);
	if (all->map.fd2 == -1)
		ft_print_error("Error:\nFile open error.");
	if (!ft_row_col(all))
		ft_print_error("Error:\nMap is not rectangular");
	ft_map_array(all);
	ft_map_wall(all);
	ft_map_element(&(all->map));
	all->mlx.window_width = all->map.num_cols * TILE_SIZE;
	all->mlx.window_height = all->map.num_rows * TILE_SIZE;
}
