/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_animations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:21:45 by madamou           #+#    #+#             */
/*   Updated: 2024/06/25 16:22:24 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	ft_put_aminations(t_mlx *mlx, void *img)
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
				mlx_put_image_to_window(mlx->init, mlx->window, img,
					x * IMAGE, y * IMAGE);
			x++;
		}
		y++;
	}
}

void	ft_explose_monster_2(t_mlx *mlx, int count2, int between_sprite)
{
	if (count2 == ((between_sprite * 11) * 2) * 7)
		ft_put_aminations(mlx, mlx->enemy7);
	else if (count2 == ((between_sprite * 11) * 2) * 8)
		ft_put_aminations(mlx, mlx->enemy8);
	else if (count2 == ((between_sprite * 11) * 2) * 9)
		ft_put_aminations(mlx, mlx->enemy9);
	else if (count2 == ((between_sprite * 11) * 2) * 10)
		ft_put_aminations(mlx, mlx->enemy10);
	else if (count2 == ((between_sprite * 11) * 2) * 11)
		ft_put_aminations(mlx, mlx->enemy11);
	else if (count2 == ((between_sprite * 11) * 2) * 12)
		ft_destroy_mlx(mlx);
}

int	ft_explose_monster(t_mlx *mlx)
{
	static int	frame;
	float		count;
	int			between_sprite;
	static int	count2;

	between_sprite = 300;
	count = ++frame % ((between_sprite * 11) * 2);
	if (count == 0)
		count2 = frame;
	else if (count2 == ((between_sprite * 11) * 2))
		ft_put_aminations(mlx, mlx->enemy1);
	else if (count2 == ((between_sprite * 11) * 2) * 2)
		ft_put_aminations(mlx, mlx->enemy2);
	else if (count2 == ((between_sprite * 11) * 2) * 3)
		ft_put_aminations(mlx, mlx->enemy3);
	else if (count2 == ((between_sprite * 11) * 2) * 4)
		ft_put_aminations(mlx, mlx->enemy4);
	else if (count2 == ((between_sprite * 11) * 2) * 5)
		ft_put_aminations(mlx, mlx->enemy5);
	else if (count2 == ((between_sprite * 11) * 2) * 6)
		ft_put_aminations(mlx, mlx->enemy6);
	ft_explose_monster_2(mlx, count2, between_sprite);
	return (0);
}

void	ft_mlx_width_height_init(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
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
