/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:06:10 by madamou           #+#    #+#             */
/*   Updated: 2024/06/21 17:13:29 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_destroy_mlx(t_mlx *mlx)
{
	if (mlx->window)
		mlx_destroy_window(mlx->init, mlx->window);
	if (mlx->back)
		mlx_destroy_image(mlx->init, mlx->back);
	if (mlx->wall)
		mlx_destroy_image(mlx->init, mlx->wall);
	if (mlx->player)
		mlx_destroy_image(mlx->init, mlx->player);
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
	if (ft_put_exit(mlx) == -1)
		return (-1);
	return (0);
}

// void  ft_put_pixel(t_mlx *mlx)
// {
// // 	t_mlx img;
// //
// // 	mlx->img.mlx_img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
//
// 	int x;
// 	int y;
//
// 	y = 0;
// 	while (y < HEIGHT)
// 	{
// 		x = 0;
// 		while (x < WIDTH)
// 		{
// 			mlx_pixel_put(mlx->init, mlx->window, x, y, 0X99BFCF);
// 			x++;
// 		}
// 		y++;
// 	}
// }
