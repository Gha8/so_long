/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohamed <gmohamed@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-01 21:26:23 by gmohamed          #+#    #+#             */
/*   Updated: 2024-11-01 21:26:23 by gmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_setup_1(t_info *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->map.num_cols)
	{
		j = 0;
		while (j < all->map.num_rows)
		{
			if (all->map.map_array[j][i] == '1')
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win_mlx,
					all->wall.img, i * TILE_SIZE, j * TILE_SIZE);
			else if (all->map.map_array[j][i] == '0')
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win_mlx,
					all->floor.img, i * TILE_SIZE, j * TILE_SIZE);
			else if (all->map.map_array[j][i] == 'P' && all->map.flag_exit)
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win_mlx,
					all->player_exit.img, i * TILE_SIZE, j * TILE_SIZE);
			else if (all->map.map_array[j][i] == 'P')
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win_mlx,
					all->player.img, i * TILE_SIZE, j * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	ft_setup_2(t_info *all)
{
	int	i;
	int	j;

	i = 0;
	while (i < all->map.num_cols)
	{
		j = 0;
		while (j < all->map.num_rows)
		{
			if (all->map.map_array[j][i] == 'E')
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win_mlx,
					all->exit.img, i * TILE_SIZE, j * TILE_SIZE);
			else if (all->map.map_array[j][i] == 'C')
				mlx_put_image_to_window(all->mlx.mlx, all->mlx.win_mlx,
					all->collectible.img, i * TILE_SIZE, j * TILE_SIZE);
			j++;
		}
		i++;
	}
}

int	ft_loop(t_info *all)
{
	ft_setup_1(all);
	ft_setup_2(all);
	return (0);
}

int	ft_file_name(char *file_name, char *cmp)
{
	int		name_point;
	int		i;

	i = 0;
	if (ft_strlen(file_name) < 5)
		return (0);
	name_point = (int)ft_strlen(file_name) - 4;
	while (file_name[name_point] && cmp[i])
	{
		if (file_name[name_point] != cmp[i])
			return (0);
		name_point++;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	all;

	if (!(argc == 2 && ft_file_name(argv[1], ".ber")))
		ft_print_error("file path/format :./so_long maps/*.ber");
	ft_init(&all);
	ft_map(argv[1], &all);
	all.mlx.mlx = mlx_init();
	all.mlx.win_mlx = mlx_new_window(all.mlx.mlx, all.mlx.window_width,
			all.mlx.window_height, "So_Long");
	ft_init_xpm(&all);
	mlx_hook(all.mlx.win_mlx, 2, 1L << 0, &keypress_event, &all);
	mlx_hook(all.mlx.win_mlx, 17, 0, &keypress, &all);
	mlx_loop_hook(all.mlx.mlx, &ft_loop, &all);
	mlx_loop(all.mlx.mlx);
	ft_free(&all);
	return (0);
}
