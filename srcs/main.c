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
#include <stdio.h>

void ft_destroy_mlx(void *mlx_open)
{
	mlx_destroy_display(mlx_open);
	free(mlx_open);
}

int main(int argc, char **argv)
{
	void *mlx_open;
	void *mlx_window;

	(void)argv;
	(void)argc;
	mlx_open = mlx_init();
	if (!mlx_open)
		return (perror("Error when init mlx\n"), 1);
	mlx_window = mlx_new_window(mlx_open, WIDTH, HEIGHT, "New window");
	if (!mlx_window)
	{
		perror("Error when creating display\n");
		return (ft_destroy_mlx(mlx_open), 1);
	}
	mlx_loop(mlx_open);
	mlx_destroy_window(mlx_open, mlx_window);
	ft_destroy_mlx(mlx_open);
	return (0);
}
