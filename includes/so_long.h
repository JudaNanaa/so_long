/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:06:56 by madamou           #+#    #+#             */
/*   Updated: 2024/06/17 13:08:04 by madamou          ###   ########.fr       */
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

#endif // !SO_LONG_H
