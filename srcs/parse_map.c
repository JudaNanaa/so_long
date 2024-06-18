/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:09:03 by madamou           #+#    #+#             */
/*   Updated: 2024/06/18 21:36:44 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>

int ft_check_if_collectible(char *map)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			cpt++;
		i++;
	}
	if (cpt == 0)
		return (ft_printf("Error \nNo collectible\n"), 0);
	return (1);
}

int ft_check_if_not_duplicate(char *map, char c, char *str)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (map[i])
	{
		if (map[i] == c)
			cpt++;
		i++;
	}
	if (cpt == 0)
		return (ft_printf("Error \nNo %s\n", str), 0);
	else if (cpt > 1)
		return (ft_printf("Error \nToo many %ss\n", str), 0);
	return (1);
}

int ft_check_if_rectangle(char *buff)
{
	int cpt;
	int len;
	int i;

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
				return (ft_printf("Error\nMap not rectangle\n"), 0);
		}
		if (buff[i])
			i++;
	}
	return (1);
}

int ft_check_close_by_wall(char *buff)
{
	int i;
	// int latt;

	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		if (buff[i] != '1')
			return (ft_printf("Error\nNot close by wall\n"), 0);
		i++;
	}
	// i = ft_strlen(buff) - 2;
	// while (buff[i] && buff[i] != '\n')
	// {
	// 	if (buff[i] != '1')
	// 		return (ft_printf("Error\nNot close by wall\n"), 0);
	// 	i--;
	// }
	// i = 0;
	// while (buff[i])
	// {
	// 	latt = 0;
	// 	while (buff[i] && buff[i] != '\n')
	// 	{
	// 		latt++;
	// 		if (latt == 1)
	// 		{
	// 			if (buff[i + latt] != '1')
	// 				return (ft_printf("Error\nNot close by wall\n"), 0);
	// 		}
	// 		i++;
	// 	}
	// 	if (buff[i - 1] != '1')
	// 		return (ft_printf("Error\nNot close by wall\n"), 0);
	// 	if (buff[i])
	// 		i++;
	// }
	return (1);
}

char *ft_read_map(int fd)
{
	char *buff;
	char *line;

	buff = NULL;
	line = get_next_line(fd);
	while (line)
	{
		buff = ft_realloc(buff, ft_strlen(line));
		if (!buff)
			return (ft_printf("Error when realloc for parsing\n"), NULL);
		buff = ft_strcat(buff, line);
		free(line);
		line = get_next_line(fd);
	}
	return (buff);
}

int ft_check_map(char *buff)
{
	int cpt;

	cpt  = 0;
	cpt += ft_check_if_not_duplicate(buff, 'P', "Player");
	cpt += ft_check_if_not_duplicate(buff, 'E', "Exit");
	cpt += ft_check_if_collectible(buff);
	cpt += ft_check_if_rectangle(buff);
	cpt += ft_check_close_by_wall(buff);
	return (cpt);
}

int ft_open_map(char *map)
{
	int fd;
	char *buff;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (ft_printf("%s : ", map), perror(""), 0);
	buff = ft_read_map(fd);
	close(fd);
	if (!buff)
		return (0);
	if (ft_check_map(buff) != 4)
		return (free(buff), 0);
	return (free(buff), 1);
}

int ft_parse_map(char *map)
{
	if (ft_strlen(map) <= 4)
		return (ft_printf("Error \nFile don't end by .ber\n"), 0);
	if (ft_strcmp(&map[ft_strlen(map) - 4], ".ber") != 0)
		return (ft_printf("Error \nFile don't end by .ber\n"), 0);
	return (ft_open_map(map));
}
