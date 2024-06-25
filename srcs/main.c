/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:06:24 by madamou           #+#    #+#             */
/*   Updated: 2024/06/25 16:54:42 by madamou          ###   ########.fr       */
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

int	ft_check_size(char **map, t_mlx *mlx)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		y++;
	}
	i = 0;
	j = 0;
	mlx_get_screen_size(mlx->init, &i, &j);
	if (x * IMAGE > i)
		return (ft_printf("Error\nMap too big in width\n"), 0);
	if (y * IMAGE > j)
		return (ft_printf("Error\nMap too big in height\n"), 0);
	return (1);
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
	ft_initialize_mlx(&mlx, map);
	mlx.init = mlx_init();
	if (!mlx.init)
		return (ft_free_split(map), perror("Error when init mlx\n"), 1);
	if (ft_check_size(map, &mlx) == 0)
	{
		ft_free_split(map);
		return (mlx_destroy_display(mlx.init), free(mlx.init), 1);
	}
	return (ft_so_long(&mlx));
}
