/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:10:59 by madamou           #+#    #+#             */
/*   Updated: 2024/06/19 21:16:59 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_check_if_collectible(char *map)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			cpt++;
		i++;
	}
	if (cpt == 0)
		return (ft_printf("Error \nNo collectible\n"), -1);
	return (0);
}

int	ft_check_if_not_duplicate(char *map, char c, char *str)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (map[i])
	{
		if (map[i] == c)
			cpt++;
		i++;
	}
	if (cpt == 0)
		return (ft_printf("Error \nNo %s\n", str), -1);
	else if (cpt > 1)
		return (ft_printf("Error \nToo many %ss\n", str), -1);
	return (0);
}

int	ft_check_if_rectangle(char *buff)
{
	int	cpt;
	int	len;
	int	i;

	i = 0;
	len = -1;
	while (buff[i])
	{
		cpt = 0;
		while (buff[i] && buff[i] != '\n')
		{
			cpt++;
			i++;
		}
		if (len == -1)
			len = cpt;
		else
		{
			if (len != cpt)
				return (ft_printf("Error\nMap not rectangle\n"), -1);
		}
		if (buff[i])
			i++;
	}
	return (-1);
}

int	ft_check_close_by_wall2(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		if (buff[i] != '1')
			return (ft_printf("Error\nNot close by wall\n"), -1);
		i++;
	}
	i = ft_strlen(buff) - 2;
	while (buff[i] && buff[i] != '\n')
	{
		if (buff[i] != '1')
			return (ft_printf("Error\nNot close by wall\n"), -1);
		i--;
	}
	return (0);
}

int	ft_check_close_by_wall(char *buff)
{
	int	i;
	int	latt;

	i = 0;
	while (buff[i])
	{
		latt = 0;
		while (buff[i] && buff[i] != '\n')
		{
			latt++;
			if (latt == 1)
			{
				if (buff[i] != '1')
					return (ft_printf("Error\nNot close by wall\n"), -1);
			}
			i++;
		}
		if (buff[i - 1] != '1')
			return (ft_printf("Error\nNot close by wall\n"), -1);
		if (buff[i])
			i++;
	}
	return (ft_check_close_by_wall2(buff));
}
