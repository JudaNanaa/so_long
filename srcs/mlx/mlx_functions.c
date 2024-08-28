/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:06:10 by madamou           #+#    #+#             */
/*   Updated: 2024/08/28 21:13:49 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <stdio.h>

void	ft_destroy_mlx(t_mlx *mlx)
{
	if (mlx->window)
		mlx_destroy_window(mlx->init, mlx->window);
	if (mlx->back)
		mlx_destroy_image(mlx->init, mlx->back);
	if (mlx->wall)
		mlx_destroy_image(mlx->init, mlx->wall);
	if (mlx->player_f)
		mlx_destroy_image(mlx->init, mlx->player_f);
	if (mlx->player_r)
		mlx_destroy_image(mlx->init, mlx->player_r);
	if (mlx->player_l)
		mlx_destroy_image(mlx->init, mlx->player_l);
	if (mlx->player_b)
		mlx_destroy_image(mlx->init, mlx->player_b);
	if (mlx->coins)
		mlx_destroy_image(mlx->init, mlx->coins);
	if (mlx->exit)
		mlx_destroy_image(mlx->init, mlx->exit);
	mlx_destroy_display(mlx->init);
	ft_free_split(mlx->map);
	free(mlx->init);
	exit(EXIT_SUCCESS);
}

void	ft_mlx_width_height_init(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
			x++;
		y++;
	}
	mlx->width = x * 64;
	mlx->height = y * 64;
}

int	ft_nb_collectible(t_mlx *mlx)
{
	int	x;
	int	y;
	int	cpt;

	cpt = 0;
	y = 0;
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'C')
				cpt++;
			x++;
		}
		y++;
	}
	return (cpt);
}

int	ft_put_pixel(t_mlx *mlx)
{
	if (ft_put_backgroud(mlx) == -1)
		return (-1);
	if (ft_put_wall(mlx) == -1)
		return (-1);
	if (ft_put_player(mlx) == -1)
		return (-1);
	if (ft_put_collectible(mlx) == -1)
		return (-1);
	return (0);
}

void	ft_parcourt_map(t_mlx *mlx, int x, int y, void *img)
{
	int	i;
	int	j;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == '1')
				mlx_put_image_to_window(mlx->init, mlx->window, img, j * x,
					i * y);
			j++;
		}
		i++;
	}
}
