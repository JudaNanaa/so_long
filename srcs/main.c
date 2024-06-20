/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:06:24 by madamou           #+#    #+#             */
/*   Updated: 2024/06/19 21:09:51 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int	ft_exit_cross(int keycode, int x, int y, t_mlx *mlx)
{
	if (keycode == 65307)
	{
		printf("You pressed on escape key. bye\n");
		mlx_destroy_window(mlx->init, mlx->window);
		ft_destroy_mlx(mlx->init);
		exit(EXIT_SUCCESS);
	}
	printf("x = %d et y = %d\n", x, y);
	printf("%s = %d\n", "touche", keycode);
	return (0);
}

int	ft_exit_escape(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
	{
		printf("You pressed on escape key. bye\n");
		mlx_destroy_window(mlx->init, mlx->window);
		ft_destroy_mlx(mlx->init);
		ft_free_split(mlx->map);
		exit(EXIT_SUCCESS);
	}
	mlx_string_put(mlx->init, mlx->window, WIDTH / 2, HEIGHT / 2,
		0X00FFFFFF, "test ?");
	printf("%s = %d\n", "touche", keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
		return (ft_printf("Pas le bon nombre d'arguments\n"), 1);
	mlx.map = ft_parse_map(argv[1]);
	if (!mlx.map)
		return (1);
	ft_free_split(mlx.map);
	// mlx.init = mlx_init();
	// if (!mlx.init)
	// 	return (perror("Error when init mlx\n"), 1);
	// mlx.window = mlx_new_window(mlx.init, WIDTH, HEIGHT, "So_long");
	// if (!mlx.window)
	// {
	// 	perror("Error when creating display\n");
	// 	return (ft_destroy_mlx(mlx.init), 1);
	// }
	// mlx_pixel_put(mlx.init, mlx.window, WIDTH / 2, HEIGHT / 2, 0X00FFFFFF);
	// mlx_key_hook(mlx.window, ft_exit_escape, &mlx);
	// mlx_mouse_hook(mlx.window, ft_exit_cross, &mlx);
	// mlx_loop(mlx.init);
	// ft_destroy_mlx(mlx.init);
	return (0);
}
