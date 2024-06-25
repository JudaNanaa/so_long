/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 02:03:26 by madamou           #+#    #+#             */
/*   Updated: 2024/06/25 14:37:12 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	ft_put_enemies(t_mlx *mlx)
{
	int	x;
	int	y;
	int	random;

	y = 0;
	srand(time(NULL));
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == '0')
			{
				random = rand() % 50;
				if (random == rand() % 50)
					mlx->map[y][x] = 'M';
			}
			x++;
		}
		y++;
	}
}

void	ft_print_enemies(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'M')
				mlx_put_image_to_window(mlx->init, mlx->window, mlx->enemy,
					x * IMAGE, y * IMAGE);
			x++;
		}
		y++;
	}
}
