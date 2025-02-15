/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohamed <gmohamed@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-01 21:24:50 by gmohamed          #+#    #+#             */
/*   Updated: 2024-11-01 21:24:50 by gmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_change_addr_player(t_info *all, int img_width, int img_height)
{
	int	i;
	int	j;
	int	c;
	int	w;

	w = img_width;
	i = 0;
	c = all->player.addr[0];
	while (i < img_width)
	{
		j = 0;
		while (j < img_height)
		{
			if (all->player.addr[i * w + j] == c)
				all->player.addr[i * w + j] = all->floor.addr[i * w + j];
			j++;
		}
		i++;
	}
}

void	ft_change_addr_pl_ex(t_info *all, int img_width, int img_height)
{
	int	i;
	int	j;
	int	c;
	int	w;

	w = img_width;
	i = 0;
	c = all->player_exit.addr[0];
	while (i < img_width)
	{
		j = 0;
		while (j < img_height)
		{
			if (all->player_exit.addr[i * w + j] == c)
				all->player_exit.addr[i * w + j] = all->exit.addr[i * w + j];
			j++;
		}
		i++;
	}
}

void	ft_change_addr_collect(t_info *all, int img_width, int img_height)
{
	int	i;
	int	j;
	int	c;
	int	w;

	w = img_width;
	i = 0;
	c = all->collectible.addr[0];
	while (i < img_width)
	{
		j = 0;
		while (j < img_height)
		{
			if (all->collectible.addr[i * w + j] == c)
				all->collectible.addr[i * w + j] = all->floor.addr[i * w + j];
			j++;
		}
		i++;
	}
}
