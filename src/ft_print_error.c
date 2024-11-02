/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmohamed <gmohamed@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-01 21:25:24 by gmohamed          #+#    #+#             */
/*   Updated: 2024-11-01 21:25:24 by gmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_print_error(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	exit(1);
}

void	ft_print_error2(char *str, t_map *map)
{
	ft_putstr(str);
	ft_putchar('\n');
	ft_map_free(map);
	exit(0);
}
