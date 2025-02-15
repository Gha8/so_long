/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohamed <gmohamed@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-01 21:25:18 by gmohamed          #+#    #+#             */
/*   Updated: 2024-11-01 21:25:18 by gmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_str_wall_row(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_str_wall_col(t_info *all, int index)
{
	int		i;
	char	cmp;

	i = 0;
	while (i < all->map.num_rows)
	{
		cmp = all->map.map_array[i][index];
		if (cmp != '1')
			return (0);
		i++;
	}
	return (1);
}

void	ft_map_wall(t_info *all)
{
	int	num_rows;
	int	num_cols;
	int	flag;

	flag = 0;
	num_rows = all->map.num_rows - 1;
	num_cols = all->map.num_cols - 1;
	if (!ft_str_wall_row(all->map.map_array[0], '1'))
		flag++;
	if (!ft_str_wall_row(all->map.map_array[num_rows], '1'))
		flag++;
	if (!ft_str_wall_col(all, 0))
		flag++;
	if (!ft_str_wall_col(all, num_cols))
		flag++;
	if (flag != 0)
	{
		ft_free(all);
		ft_print_error("Error:\nMap must be closed by Wall");
	}
}
