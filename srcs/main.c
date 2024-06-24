/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:06:24 by madamou           #+#    #+#             */
/*   Updated: 2024/06/21 20:17:12 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

void	ft_find_position_player(t_mlx *mlx, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'P' || mlx->map[i][j] == 'R'
				|| mlx->map[i][j] == 'L' || mlx->map[i][j] == 'B')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_find_position_exit(t_mlx *mlx, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'E')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	ft_is_doable(t_mlx *mlx, int keycode)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	ft_find_position_player(mlx, &x, &y);
	if (keycode == 'w' && mlx->map[y - 1][x] != '1')
		return (mlx->map[y - 1][x] = 'B', mlx->map[y][x] = '0', 1);
	if (keycode == 's' && mlx->map[y + 1][x] != '1')
		return (mlx->map[y + 1][x] = 'P', mlx->map[y][x] = '0', 1);
	if (keycode == 'a' && mlx->map[y][x - 1] != '1')
		return (mlx->map[y][x - 1] = 'L', mlx->map[y][x] = '0', 1);
	if (keycode == 'd' && mlx->map[y][x + 1] != '1')
		return (mlx->map[y][x + 1] = 'R', mlx->map[y][x] = '0', 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	char	**map;

	if (argc != 2)
		return (ft_printf("Pas le bon nombre d'arguments\n"), 1);
	map = ft_parse_map(argv[1]);
	if (!map)
		return (1);
	return (ft_so_long(&mlx, map));
}
