/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:15:12 by madamou           #+#    #+#             */
/*   Updated: 2024/06/25 14:35:07 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	ft_put_backgroud(t_mlx *mlx)
{
	int	i;
	int	j;

	j = 0;
	while (mlx->map[j])
	{
		i = 0;
		while (mlx->map[j][i])
		{
			if (mlx->map[j][i] == '0' || mlx->map[j][i] == 'E')
				mlx_put_image_to_window(mlx->init, mlx->window, mlx->back,
					i * IMAGE, j * IMAGE);
			if (mlx->map[j][i] == 'E')
				mlx->map[j][i] = '0';
			i++;
		}
		j++;
	}
	return (0);
}

int	ft_put_wall(t_mlx *mlx)
{
	int	x;
	int	y;

	x = IMAGE;
	y = IMAGE;
	ft_parcourt_map(mlx, x, y, mlx->wall);
	return (0);
}

int	ft_put_player(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (mlx->map[++i])
	{
		j = -1;
		while (mlx->map[i][++j])
		{
			if (mlx->map[i][j] == 'R')
				mlx_put_image_to_window(mlx->init, mlx->window, mlx->player_r,
					j * IMAGE, i * IMAGE);
			else if (mlx->map[i][j] == 'P')
				mlx_put_image_to_window(mlx->init, mlx->window, mlx->player_f,
					j * IMAGE, i * IMAGE);
			else if (mlx->map[i][j] == 'B')
				mlx_put_image_to_window(mlx->init, mlx->window, mlx->player_b,
					j * IMAGE, i * IMAGE);
			else if (mlx->map[i][j] == 'L')
				mlx_put_image_to_window(mlx->init, mlx->window, mlx->player_l,
					j * IMAGE, i * IMAGE);
		}
	}
	return (0);
}

int	ft_put_collectible(t_mlx *mlx)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = IMAGE;
	y = IMAGE;
	i = 0;
	while (mlx->map[i])
	{
		j = -1;
		while (mlx->map[i][++j])
			if (mlx->map[i][j] == 'C')
				mlx_put_image_to_window(mlx->init, mlx->window, mlx->coins,
					j * x, i * y);
		i++;
	}
	return (0);
}

int	ft_put_exit(t_mlx *mlx)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = IMAGE;
	y = IMAGE;
	i = 0;
	if (mlx->map[mlx->exit_y][mlx->exit_x] != 'P'
		&& mlx->map[mlx->exit_y][mlx->exit_x] != 'R'
		&& mlx->map[mlx->exit_y][mlx->exit_x] != 'B'
		&& mlx->map[mlx->exit_y][mlx->exit_x] != 'L')
		mlx->map[mlx->exit_y][mlx->exit_x] = 'E';
	while (mlx->map[i])
	{
		j = -1;
		while (mlx->map[i][++j])
			if (mlx->map[i][j] == 'E')
				mlx_put_image_to_window(mlx->init, mlx->window, mlx->exit,
					j * x, i * y);
		i++;
	}
	return (0);
}
