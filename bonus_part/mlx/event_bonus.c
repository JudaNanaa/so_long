/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:16:09 by madamou           #+#    #+#             */
/*   Updated: 2024/06/25 14:36:54 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"
#include <time.h>

int	ft_exit_cross(t_mlx *mlx)
{
	ft_destroy_mlx(mlx);
	return (0);
}

int	ft_check_input(int keycode, t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	ft_find_position_player(mlx, &x, &y);
	if (ft_is_doable(mlx, keycode) == 1)
	{
		if (ft_nb_enemies(mlx) != mlx->nb_enemies)
			ft_destroy_mlx(mlx);
		ft_put_player(mlx);
		mlx_put_image_to_window(mlx->init, mlx->window, mlx->back,
			x * 64, y * 64);
		mlx_put_image_to_window(mlx->init, mlx->window, mlx->wall, 0, 0);
		mlx_put_image_to_window(mlx->init, mlx->window, mlx->wall, 64, 0);
		return (1);
	}
	return (0);
}

int	ft_string_to_image(int keycode, t_mlx *mlx, int cpt)
{
	char	*result;
	char	*string;

	if (ft_check_input(keycode, mlx) == 1)
	{
		result = ft_itoa(cpt);
		if (!result)
			ft_destroy_mlx(mlx);
		string = ft_strjoin("move : ", result);
		if (!string)
			(free(result), ft_destroy_mlx(mlx));
		mlx_string_put(mlx->init, mlx->window, 50, 50, 0X0FF0000, string);
		(free(result), free(string));
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
	{
		if (ft_string_to_image(keycode, mlx, cpt) == 1)
			cpt++;
	}
	if (ft_nb_collectible(mlx) == 0)
		ft_put_exit(mlx);
	ft_find_position_exit(mlx, &x, &y);
	if (ft_nb_collectible(mlx) == 0 && y == 0 && x == 0)
		mlx_loop_hook(mlx->init, ft_explose_monster, mlx);
	return (0);
}
