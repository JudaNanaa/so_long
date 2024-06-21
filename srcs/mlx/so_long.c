/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:39:37 by madamou           #+#    #+#             */
/*   Updated: 2024/06/21 17:03:50 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_initalize_mlx(t_mlx *mlx, char **map)
{
	mlx->map = map;
	ft_mlx_width_height_init(mlx);
	mlx->wall = NULL;
	mlx->window = NULL;
	mlx->back = NULL;
	mlx->player = NULL;
	mlx->coins = NULL;
	mlx->exit = NULL;
}

int	ft_so_long(t_mlx *mlx, char **map)
{
	ft_initalize_mlx(mlx, map);
	mlx->init = mlx_init();
	if (!mlx->init)
		return (perror("Error when init mlx\n"), 1);
	mlx->window = mlx_new_window(mlx->init, mlx->width, mlx->height, "So_long");
	if (!mlx->window)
	{
		perror("Error when creating display\n");
		return (ft_destroy_mlx(mlx), 1);
	}
	if (ft_put_pixel(mlx) == -1)
		ft_destroy_mlx(mlx);
	mlx_key_hook(mlx->window, ft_exit_escape, mlx);
	mlx_mouse_hook(mlx->window, ft_exit_cross, mlx);
	mlx_loop(mlx->init);
	ft_destroy_mlx(mlx->init);
	return (0);
}
