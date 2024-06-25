/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:28:13 by madamou           #+#    #+#             */
/*   Updated: 2024/06/25 14:36:33 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	ft_place_enemies(t_mlx *mlx, int x, int y)
{
	int	random;

	random = rand() % 4;
	if (random == 0 && mlx->map[y - 1][x] != 'C' && mlx->map[y - 1][x] != 'E'
		&& mlx->map[y - 1][x] != '1' && mlx->map[y - 1][x] != 'M' && mlx->map[y
		- 1][x] != 'A')
		mlx->map[y - 1][x] = 'A';
	else if (random == 1 && mlx->map[y][x + 1] != 'C' && mlx->map[y][x
			+ 1] != 'E' && mlx->map[y][x + 1] != '1' && mlx->map[y][x
			+ 1] != 'M' && mlx->map[y][x + 1] != 'A')
		mlx->map[y][x + 1] = 'A';
	else if (random == 2 && mlx->map[y + 1][x] != 'C' && mlx->map[y
			+ 1][x] != 'E' && mlx->map[y + 1][x] != '1' && mlx->map[y
			+ 1][x] != 'M' && mlx->map[y + 1][x] != 'A')
		mlx->map[y + 1][x] = 'A';
	else if (random == 3 && mlx->map[y][x - 1] != 'C' && mlx->map[y][x
			- 1] != 'E' && mlx->map[y][x - 1] != '1' && mlx->map[y][x
			- 1] != 'M' && mlx->map[y][x - 1] != 'A')
		mlx->map[y][x - 1] = 'A';
	else
		mlx->map[y][x] = 'A';
}

void	ft_change_a(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'A')
				mlx->map[y][x] = 'M';
			x++;
		}
		y++;
	}
}

int	ft_nb_enemies(t_mlx *mlx)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'M')
				i++;
			x++;
		}
		y++;
	}
	return (i);
}

void	ft_print_enemies_on_display(t_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'A')
			{
				mlx_put_image_to_window(mlx->init, mlx->window, mlx->enemy,
					x * IMAGE, y * IMAGE);
				mlx->map[y][x] = 'M';
			}
			else if (mlx->map[y][x] == 'M')
			{
				mlx_put_image_to_window(mlx->init, mlx->window, mlx->back,
					x * IMAGE, y * IMAGE);
				mlx->map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

int	ft_move_enemies(t_mlx *mlx)
{
	int			x;
	int			y;
	static int	frame;

	while (frame++ == 10000)
	{
		y = -1;
		while (mlx->map[++y])
		{
			x = -1;
			while (mlx->map[y][++x])
			{
				if (mlx->map[y][x] == 'M')
					ft_place_enemies(mlx, x, y);
			}
		}
		(ft_print_enemies_on_display(mlx),
			ft_find_position_player(mlx, &x, &y));
		if (x == 0 && y == 0)
			ft_destroy_mlx(mlx);
		frame = 0;
	}
	return (0);
}
