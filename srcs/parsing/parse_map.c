/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:09:03 by madamou           #+#    #+#             */
/*   Updated: 2024/06/19 21:17:05 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*ft_read_map(int fd)
{
	char	*buff;
	char	*line;

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

int	ft_check_map(char *buff)
{
	int	cpt;

	cpt = 0;
	cpt += ft_check_if_not_duplicate(buff, 'P', "Player");
	cpt += ft_check_if_not_duplicate(buff, 'E', "Exit");
	cpt += ft_check_if_collectible(buff);
	cpt += ft_check_if_rectangle(buff);
	cpt += ft_check_close_by_wall(buff);
	cpt += ft_check_if_playable(buff);
	return (cpt);
}

char **ft_open_map(char *map)
{
	int		fd;
	char	*buff;
	char	**split;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (ft_printf("%s : ", map), perror(""), NULL);
	buff = ft_read_map(fd);
	close(fd);
	if (!buff)
		return (NULL);
	if (ft_check_map(buff) < 0)
		return (free(buff), NULL);
	return (split = ft_split(buff, "\n"), free(buff), split);
}

char	**ft_parse_map(char *map)
{
	if (ft_strlen(map) <= 4)
		return (ft_printf("Error \nFile don't end by .ber\n"), NULL);
	if (ft_strcmp(&map[ft_strlen(map) - 4], ".ber") != 0)
		return (ft_printf("Error \nFile don't end by .ber\n"), NULL);
	return (ft_open_map(map));
}
