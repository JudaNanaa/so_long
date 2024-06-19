/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:06:56 by madamou           #+#    #+#             */
/*   Updated: 2024/06/19 21:13:32 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include <stdio.h>

# define WIDTH 1900
# define HEIGHT 1080

typedef struct s_mlx
{
	void  *init;
	void  *window;
}t_mlx;

int	ft_check_if_collectible(char *map);
int ft_parse_map(char *map);
int	ft_check_if_not_duplicate(char *map, char c, char *str);
int	ft_check_if_rectangle(char *buff);
int	ft_check_close_by_wall2(char *buff);
int	ft_check_close_by_wall(char *buff);

void	ft_destroy_mlx(void *mlx);

#endif // !SO_LONG_H
