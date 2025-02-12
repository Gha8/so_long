/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohamed <gmohamed@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-01 21:25:04 by gmohamed          #+#    #+#             */
/*   Updated: 2024-11-01 21:25:04 by gmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	keypress_event(int keycode, t_info *all)
{
	static int	flag;

	if (flag == 0)
		all->count_movement = 0;
	flag++;
	if (keycode == 65307)
		exit(0);
	else if (keycode == 119)
		ft_player_move(all, 'U');
	else if (keycode == 115)
		ft_player_move(all, 'D');
	else if (keycode == 97)
		ft_player_move(all, 'L');
	else if (keycode == 100)
		ft_player_move(all, 'R');
	return (0);
}

int	keypress(t_info *all)
{
	ft_free(all);
	ft_destroy(all);
	exit(0);
}
