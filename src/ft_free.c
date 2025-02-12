/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohamed <gmohamed@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-01 21:24:39 by gmohamed          #+#    #+#             */
/*   Updated: 2024-11-01 21:24:39 by gmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_map_free(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_array[i])
		free(map->map_array[i++]);
	free(map->map_array);
}

void	ft_destroy(t_info *all)
{
	if (all->wall.img)
		mlx_destroy_image(all->mlx.mlx, all->wall.img);
	if (all->floor.img)
		mlx_destroy_image(all->mlx.mlx, all->floor.img);
	if (all->player.img)
		mlx_destroy_image(all->mlx.mlx, all->player.img);
	if (all->collectible.img)
		mlx_destroy_image(all->mlx.mlx, all->collectible.img);
	if (all->exit.img)
		mlx_destroy_image(all->mlx.mlx, all->exit.img);
	if (all->player_exit.img)
		mlx_destroy_image(all->mlx.mlx, all->player_exit.img);
	if (all->mlx.win_mlx)
		mlx_destroy_window(all->mlx.mlx, all->mlx.win_mlx);
	if (all->mlx.mlx)
	{
		mlx_destroy_display(all->mlx.mlx);
		free(all->mlx.mlx);
		all->mlx.mlx = NULL;
	}
}

void	ft_free(t_info *all)
{
	int	i;

	i = 0;
	if (all->map.map_array)
	{
		while (all->map.map_array[i])
			free(all->map.map_array[i++]);
		free(all->map.map_array);
	}
	close(all->map.fd);
	close(all->map.fd2);
}
