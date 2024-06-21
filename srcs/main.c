/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:06:24 by madamou           #+#    #+#             */
/*   Updated: 2024/06/21 11:45:02 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

int	ft_exit_cross(int keycode, int x, int y, t_mlx *mlx)
{
	if (keycode == 802)
	{
		printf("You pressed on escape key. bye\n");
		ft_destroy_mlx(mlx);
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
		ft_destroy_mlx(mlx);
	}
	printf("%s = %d\n", "touche", keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	char	**map;

	if (argc != 2)
		return (ft_printf("Pas le bon nombre d'arguments\n"), 1);
	map = ft_parse_map(argv[1]);
	if (!map)
		return (1);
	return (ft_so_long(&mlx, map));
}
