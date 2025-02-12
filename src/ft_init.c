/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohamed <gmohamed@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-01 21:24:55 by gmohamed          #+#    #+#             */
/*   Updated: 2024-11-01 21:24:55 by gmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init(t_info *all)
{
	all->mlx.mlx = 0;
	all->mlx.win_mlx = 0;
	all->wall.img = 0;
	all->floor.img = 0;
	all->player.img = 0;
	all->collectible.img = 0;
	all->exit.img = 0;
	all->player_exit.img = 0;
	all->map.map_array = NULL;
}
