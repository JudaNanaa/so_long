/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:39:37 by madamou           #+#    #+#             */
/*   Updated: 2024/06/25 16:09:35 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <stdio.h>

void	ft_initialize_image2(t_mlx *mlx, int x, int y)
{
	mlx->back = mlx_xpm_file_to_image(mlx->init, IMG_FLOOR, &x, &y);
	if (!mlx->back || x != IMAGE || y != IMAGE)
		(ft_printf("Error with back\n"), ft_destroy_mlx(mlx));
	mlx->wall = mlx_xpm_file_to_image(mlx->init, IMG_WALL, &x, &y);
	if (!mlx->wall || x != IMAGE || y != IMAGE)
		(ft_printf("Error with wall\n"), ft_destroy_mlx(mlx));
	mlx->coins = mlx_xpm_file_to_image(mlx->init, IMG_COINS, &x, &y);
	if (!mlx->coins || x != IMAGE || y != IMAGE)
		(ft_printf("Error with coins\n"), ft_destroy_mlx(mlx));
	mlx->exit = mlx_xpm_file_to_image(mlx->init, IMG_EXIT, &x, &y);
	if (!mlx->exit || x != IMAGE || y != IMAGE)
		(ft_printf("Error with exit\n"), ft_destroy_mlx(mlx));
}

void	ft_initialize_image(t_mlx *mlx)
{
	int	x;
	int	y;

	x = IMAGE;
	y = IMAGE;
	mlx->player_f = mlx_xpm_file_to_image(mlx->init, IMG_FRONT, &x, &y);
	if (!mlx->player_f || x != IMAGE || y != IMAGE)
		(ft_printf("Error with perso_front\n"), ft_destroy_mlx(mlx));
	mlx->player_r = mlx_xpm_file_to_image(mlx->init, IMG_RIGHT, &x, &y);
	if (!mlx->player_r || x != IMAGE || y != IMAGE)
		(ft_printf("Error with perso_right\n"), ft_destroy_mlx(mlx));
	mlx->player_l = mlx_xpm_file_to_image(mlx->init, IMG_LEFT, &x, &y);
	if (!mlx->player_l || x != IMAGE || y != IMAGE)
		(ft_printf("Error with perso_left\n"), ft_destroy_mlx(mlx));
	mlx->player_b = mlx_xpm_file_to_image(mlx->init, IMG_BACK, &x, &y);
	if (!mlx->player_b || x != IMAGE || y != IMAGE)
		(ft_printf("Error with perso_back\n"), ft_destroy_mlx(mlx));
	ft_initialize_image2(mlx, x, y);
}

void	ft_initialize_mlx(t_mlx *mlx, char **map)
{
	mlx->map = map;
	ft_mlx_width_height_init(mlx);
	mlx->wall = NULL;
	mlx->window = NULL;
	mlx->back = NULL;
	mlx->player_f = NULL;
	mlx->player_r = NULL;
	mlx->player_l = NULL;
	mlx->player_b = NULL;
	mlx->coins = NULL;
	mlx->exit = NULL;
	mlx->exit_x = 0;
	mlx->exit_y = 0;
	ft_find_position_exit(mlx, &mlx->exit_x, &mlx->exit_y);
}

int	ft_so_long(t_mlx *mlx)
{
	ft_initialize_image(mlx);
	mlx->window = mlx_new_window(mlx->init, mlx->width, mlx->height, "So_long");
	if (!mlx->window)
	{
		perror("Error when creating display\n");
		return (ft_destroy_mlx(mlx), 1);
	}
	if (ft_put_pixel(mlx) == -1)
		ft_destroy_mlx(mlx);
	mlx_hook(mlx->window, 2, 1L << 0, ft_exit_escape, mlx);
	mlx_hook(mlx->window, 17, 0L, ft_exit_cross, mlx);
	mlx_loop(mlx->init);
	ft_destroy_mlx(mlx->init);
	return (0);
}
