/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:15:12 by madamou           #+#    #+#             */
/*   Updated: 2024/06/21 17:04:48 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_put_backgroud(t_mlx *mlx)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 3;
	y = 3;
	mlx->back = mlx_xpm_file_to_image(mlx->init, "images/back.xpm", &x, &y);
	if (!mlx->back)
		return (ft_printf("Error when adding back\n"), -1);
	j = 0;
	while (j < mlx->height)
	{
		i = 0;
		while (i < mlx->width)
		{
			mlx_put_image_to_window(mlx->init, mlx->window, mlx->back, i, j);
			i += x;
		}
		j += y;
	}
	return (0);
}

int	ft_put_wall(t_mlx *mlx)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	mlx->wall = mlx_xpm_file_to_image(mlx->init, "images/bush1.xpm", &x, &y);
	if (!mlx->wall)
		return (ft_printf("Error when adding wall\n"), -1);
	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == '1')
				mlx_put_image_to_window(mlx->init, mlx->window, mlx->wall,
					j * x, i * y);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_put_player(t_mlx *mlx)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	mlx->player = mlx_xpm_file_to_image(mlx->init, "images/perso1.xpm", &x, &y);
	if (!mlx->player)
		return (ft_printf("Error when adding player\n"), -1);
	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'P')
				mlx_put_image_to_window(mlx->init, mlx->window, mlx->player,
					j * x, i * y);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_put_collectible(t_mlx *mlx)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	mlx->coins = mlx_xpm_file_to_image(mlx->init, "images/coin1.xpm", &x, &y);
	if (!mlx->coins)
		return (ft_printf("Error when adding collectible\n"), -1);
	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'C')
				mlx_put_image_to_window(mlx->init, mlx->window, mlx->coins,
					j * x, i * y);
			j++;
		}
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

	x = 0;
	y = 0;
	mlx->exit = mlx_xpm_file_to_image(mlx->init, "images/exit.xpm", &x, &y);
	if (!mlx->exit)
		return (ft_printf("Error when adding the exit\n"), -1);
	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'E')
				mlx_put_image_to_window(mlx->init, mlx->window, mlx->exit,
					j * x, i * y);
			j++;
		}
		i++;
	}
	return (0);
}
