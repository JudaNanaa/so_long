/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:06:24 by madamou           #+#    #+#             */
/*   Updated: 2024/06/17 15:39:30 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void ft_destroy_mlx(void *mlx)
{
	mlx_destroy_display(mlx);
	free(mlx);
}

int test(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
	{
		printf("You pressed on escape key. bye\n");
		mlx_destroy_window(mlx->init, mlx->window);
		ft_destroy_mlx(mlx->init);
		exit(EXIT_SUCCESS);
	}
	printf("%s = %d\n", "touche", keycode);
	return (0);
}

int main(int argc, char **argv)
{
	t_mlx mlx;

	(void)argv;
	(void)argc;
	mlx.init = mlx_init();
	if (!mlx.init)
		return (perror("Error when init mlx\n"), 1);
	mlx.window = mlx_new_window(mlx.init, WIDTH, HEIGHT, "New window");
	if (!mlx.window)
	{
		perror("Error when creating display\n");
		return (ft_destroy_mlx(mlx.init), 1);
	}
	mlx_pixel_put(mlx.init, mlx.window, 250, 250, 0X00FFFFFF);
	mlx_key_hook(mlx.window, test, &mlx);
	mlx_loop(mlx.init);
	mlx_destroy_window(mlx.init, mlx.window);
	ft_destroy_mlx(mlx.init);
	return (0);
}
