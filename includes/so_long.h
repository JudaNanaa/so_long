/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:06:56 by madamou           #+#    #+#             */
/*   Updated: 2024/06/21 17:03:28 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_mlx
{
	void	*init;
	void	*window;
	void	*back;
	void	*wall;
	void	*coins;
	void	*exit;
	void	*player;
	char	**map;
	int		width;
	int		height;
	t_img	img;
}			t_mlx;

int			ft_check_if_collectible(char *map);
int			ft_check_if_not_duplicate(char *map, char c, char *str);
int			ft_check_if_rectangle(char *buff);
int			ft_check_close_by_wall2(char *buff);
int			ft_check_close_by_wall(char *buff);
int			ft_check_if_playable(char *buff);
int			ft_put_pixel(t_mlx *mlx);
int			ft_so_long(t_mlx *mlx, char **map);
int			ft_exit_escape(int keycode, t_mlx *mlx);
int			ft_exit_cross(int keycode, int x, int y, t_mlx *mlx);
int			ft_put_backgroud(t_mlx *mlx);
int			ft_put_wall(t_mlx *mlx);
int			ft_put_player(t_mlx *mlx);
int			ft_put_collectible(t_mlx *mlx);
int			ft_put_exit(t_mlx *mlx);

void		ft_destroy_mlx(t_mlx *mlx);
void		ft_mlx_width_height_init(t_mlx *mlx);

char		**ft_parse_map(char *map);

#endif // !SO_LONG_H
