/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:16:09 by madamou           #+#    #+#             */
/*   Updated: 2024/06/24 23:48:20 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	ft_exit_cross(t_mlx *mlx)
{
	ft_destroy_mlx(mlx);
	return (0);
}

int	ft_check_input(int keycode, t_mlx *mlx)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	ft_find_position_player(mlx, &x, &y);
	if (ft_is_doable(mlx, keycode) == 1)
	{
		ft_put_player(mlx);
		mlx_put_image_to_window(mlx->init, mlx->window, mlx->back,
			x * 64, y * 64);
		return (1);
	}
	return (0);
}

int	ft_exit_escape(int keycode, t_mlx *mlx)
{
	static int	cpt;
	int			x;
	int			y;

	x = 0;
	y = 0;
	if (keycode == 65307)
		ft_destroy_mlx(mlx);
	if (keycode == 'w' || keycode == 'a' || keycode == 's' || keycode == 'd')
		if (ft_check_input(keycode, mlx) == 1)
			ft_printf("The number of movement is %d\n", cpt++);
	if (ft_nb_collectible(mlx) == 0)
		if (ft_put_exit(mlx) == -1)
			ft_destroy_mlx(mlx);
	ft_find_position_exit(mlx, &x, &y);
	if (ft_nb_collectible(mlx) == 0 && y == 0 && x == 0)
		ft_destroy_mlx(mlx);
	return (0);
}