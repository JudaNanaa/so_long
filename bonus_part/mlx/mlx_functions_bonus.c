/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:06:10 by madamou           #+#    #+#             */
/*   Updated: 2024/06/25 14:37:34 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"
#include <stdio.h>

void	ft_destroy_mlx_2(t_mlx *mlx)
{
	if (mlx->enemy)
		mlx_destroy_image(mlx->init, mlx->enemy);
	if (mlx->coins)
		mlx_destroy_image(mlx->init, mlx->coins);
	if (mlx->exit)
		mlx_destroy_image(mlx->init, mlx->exit);
	if (mlx->enemy1)
		mlx_destroy_image(mlx->init, mlx->enemy1);
	if (mlx->enemy2)
		mlx_destroy_image(mlx->init, mlx->enemy2);
	if (mlx->enemy3)
		mlx_destroy_image(mlx->init, mlx->enemy3);
	if (mlx->enemy4)
		mlx_destroy_image(mlx->init, mlx->enemy4);
	if (mlx->enemy5)
		mlx_destroy_image(mlx->init, mlx->enemy5);
	if (mlx->enemy6)
		mlx_destroy_image(mlx->init, mlx->enemy6);
	if (mlx->enemy7)
		mlx_destroy_image(mlx->init, mlx->enemy7);
	if (mlx->enemy8)
		mlx_destroy_image(mlx->init, mlx->enemy8);
	if (mlx->enemy9)
		mlx_destroy_image(mlx->init, mlx->enemy9);
}

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
	if (mlx->enemy10)
		mlx_destroy_image(mlx->init, mlx->enemy10);
	if (mlx->enemy11)
		mlx_destroy_image(mlx->init, mlx->enemy11);
	ft_destroy_mlx_2(mlx);
	mlx_destroy_display(mlx->init);
	ft_free_split(mlx->map);
	free(mlx->init);
	exit(EXIT_SUCCESS);
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
	ft_print_enemies(mlx);
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
				mlx_put_image_to_window(mlx->init, mlx->window, img,
					j * x, i * y);
			j++;
		}
		i++;
	}
}
