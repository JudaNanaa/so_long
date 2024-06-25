/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:39:37 by madamou           #+#    #+#             */
/*   Updated: 2024/06/25 16:14:08 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"
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
	mlx->enemy = mlx_xpm_file_to_image(mlx->init, IMG_ENEMY, &x, &y);
	if (!mlx->enemy || x != IMAGE || y != IMAGE)
		(ft_printf("Error with exit\n"), ft_destroy_mlx(mlx));
	mlx->enemy1 = mlx_xpm_file_to_image(mlx->init, IMG_ENEMY1, &x, &y);
	if (!mlx->enemy1 || x != IMAGE || y != IMAGE)
		(ft_printf("Error with enemy1\n"), ft_destroy_mlx(mlx));
	mlx->enemy2 = mlx_xpm_file_to_image(mlx->init, IMG_ENEMY2, &x, &y);
	if (!mlx->enemy2 || x != IMAGE || y != IMAGE)
		(ft_printf("Error with enemy2\n"), ft_destroy_mlx(mlx));
	mlx->enemy3 = mlx_xpm_file_to_image(mlx->init, IMG_ENEMY3, &x, &y);
	if (!mlx->enemy3 || x != IMAGE || y != IMAGE)
		(ft_printf("Error with enemy3\n"), ft_destroy_mlx(mlx));
}

void	ft_initialize_image3(t_mlx *mlx, int x, int y)
{
	mlx->enemy4 = mlx_xpm_file_to_image(mlx->init, IMG_ENEMY4, &x, &y);
	if (!mlx->enemy4 || x != IMAGE || y != IMAGE)
		(ft_printf("Error with enemy4\n"), ft_destroy_mlx(mlx));
	mlx->enemy5 = mlx_xpm_file_to_image(mlx->init, IMG_ENEMY5, &x, &y);
	if (!mlx->enemy5 || x != IMAGE || y != IMAGE)
		(ft_printf("Error with enemy5\n"), ft_destroy_mlx(mlx));
	mlx->enemy6 = mlx_xpm_file_to_image(mlx->init, IMG_ENEMY6, &x, &y);
	if (!mlx->enemy6 || x != IMAGE || y != IMAGE)
		(ft_printf("Error with enemy6\n"), ft_destroy_mlx(mlx));
	mlx->enemy7 = mlx_xpm_file_to_image(mlx->init, IMG_ENEMY7, &x, &y);
	if (!mlx->enemy7 || x != IMAGE || y != IMAGE)
		(ft_printf("Error with enemy7\n"), ft_destroy_mlx(mlx));
	mlx->enemy8 = mlx_xpm_file_to_image(mlx->init, IMG_ENEMY8, &x, &y);
	if (!mlx->enemy8 || x != IMAGE || y != IMAGE)
		(ft_printf("Error with enemy8\n"), ft_destroy_mlx(mlx));
	mlx->enemy9 = mlx_xpm_file_to_image(mlx->init, IMG_ENEMY9, &x, &y);
	if (!mlx->enemy9 || x != IMAGE || y != IMAGE)
		(ft_printf("Error with enemy9\n"), ft_destroy_mlx(mlx));
	mlx->enemy10 = mlx_xpm_file_to_image(mlx->init, IMG_ENEMY10, &x, &y);
	if (!mlx->enemy10 || x != IMAGE || y != IMAGE)
		(ft_printf("Error with enemy10\n"), ft_destroy_mlx(mlx));
	mlx->enemy11 = mlx_xpm_file_to_image(mlx->init, IMG_ENEMY11, &x, &y);
	if (!mlx->enemy11 || x != IMAGE || y != IMAGE)
		(ft_printf("Error with enemy11\n"), ft_destroy_mlx(mlx));
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
	ft_initialize_image3(mlx, x, y);
}

void	ft_initialize_mlx(t_mlx *mlx)
{
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
	mlx->enemy = NULL;
	mlx->enemy1 = NULL;
	mlx->enemy2 = NULL;
	mlx->enemy3 = NULL;
	mlx->enemy4 = NULL;
	mlx->enemy5 = NULL;
	mlx->enemy6 = NULL;
	mlx->enemy7 = NULL;
	mlx->enemy8 = NULL;
	mlx->enemy9 = NULL;
	mlx->enemy10 = NULL;
	mlx->enemy11 = NULL;
	ft_find_position_exit(mlx, &mlx->exit_x, &mlx->exit_y);
}

int	ft_so_long(t_mlx *mlx)
{
	ft_put_enemies(mlx);
	mlx->nb_enemies = ft_nb_enemies(mlx);
	mlx->init = mlx_init();
	if (!mlx->init)
		return (perror("Error when init mlx\n"), 1);
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
	mlx_loop_hook(mlx->init, ft_move_enemies, mlx);
	mlx_loop(mlx->init);
	ft_destroy_mlx(mlx->init);
	return (0);
}
