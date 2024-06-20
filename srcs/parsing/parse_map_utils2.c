/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:14:00 by madamou           #+#    #+#             */
/*   Updated: 2024/06/20 11:14:21 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/so_long.h"
#include <stdio.h>

int ft_change_to_P(char **map, int x, int y)
{
	int cpt;

	cpt = 0;
	if (map[y][x - 1] == '0' || map[y][x - 1] == 'C' || map[y][x - 1] == 'E')
	{
		map[y][x - 1] = 'P';
		cpt++;
	}
	if (map[y][x + 1] == '0' || map[y][x + 1] == 'C' || map[y][x + 1] == 'E')
	{
		map[y][x + 1] = 'P';
		cpt++;
	}
	if (map[y - 1][x] == '0' || map[y - 1][x] == 'C' || map[y - 1][x] == 'E')
	{
		map[y - 1][x] = 'P';
		cpt++;
	}
	if (map[y + 1][x] == '0' || map[y + 1][x] == 'C' || map[y + 1][x] == 'E')
	{
		map[y + 1][x] = 'P';
		cpt++;
	}
	return (cpt);
}

char  **ft_blob_the_map(char **map)
{
	int x;
	int y;
	int cpt;

	while (1)
	{
		cpt = 0;
		y = 0;
		while (map[y])
		{
			x = 0;
			while (map[y][x])
			{
				if (map[y][x] == 'P')
					cpt += ft_change_to_P(map, x, y);
				x++;
			}
			y++;
		}
		if (cpt == 0)
			return (map);
	}
	return (NULL);
}

int ft_check_if_all_good(char **map)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

int ft_check_if_playable(char *buff)
{
	int i;
	int j;
	char **map;

	i = 0;
	j = 0;
	map = ft_split(buff, "\n");
	if (!map)
		return (-1);
	ft_blob_the_map(map);
	if (ft_check_if_all_good(map) == -1)
	{
		ft_printf("Error\nMap no playable\n");
		return (ft_free_split(map), -1);
	}
	ft_free_split(map);
	return (0);
}

