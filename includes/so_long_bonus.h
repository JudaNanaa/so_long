/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madamou <madamou@contact.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:06:56 by madamou           #+#    #+#             */
/*   Updated: 2024/06/25 16:14:40 by madamou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdio.h>

# define IMAGE 64
# define IMG_RIGHT "images/perso_right.xpm"
# define IMG_LEFT "images/perso_left.xpm"
# define IMG_BACK "images/perso_back.xpm"
# define IMG_FRONT "images/perso_front.xpm"
# define IMG_FLOOR "images/back.xpm"
# define IMG_WALL "images/bush1.xpm"
# define IMG_COINS "images/coin1.xpm"
# define IMG_EXIT "images/exit.xpm"
# define IMG_ENEMY "images/enemy.xpm"
# define IMG_ENEMY1 "images/enemy1.xpm"
# define IMG_ENEMY2 "images/enemy2.xpm"
# define IMG_ENEMY3 "images/enemy3.xpm"
# define IMG_ENEMY4 "images/enemy4.xpm"
# define IMG_ENEMY5 "images/enemy5.xpm"
# define IMG_ENEMY6 "images/enemy6.xpm"
# define IMG_ENEMY7 "images/enemy7.xpm"
# define IMG_ENEMY8 "images/enemy8.xpm"
# define IMG_ENEMY9 "images/enemy9.xpm"
# define IMG_ENEMY10 "images/enemy10.xpm"
# define IMG_ENEMY11 "images/enemy11.xpm"

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
	void	*player_f;
	void	*player_r;
	void	*player_b;
	void	*player_l;
	char	**map;
	int		width;
	int		height;
	int		exit_x;
	int		exit_y;
	void	*enemy;
	void	*enemy1;
	void	*enemy2;
	void	*enemy3;
	void	*enemy4;
	void	*enemy5;
	void	*enemy6;
	void	*enemy7;
	void	*enemy8;
	void	*enemy9;
	void	*enemy10;
	void	*enemy11;
	int		nb_enemies;
	t_img	img;
}			t_mlx;

int			ft_explose_monster(t_mlx *mlx);
int			ft_nb_enemies(t_mlx *mlx);
int			ft_check_if_collectible(char *map);
int			ft_check_if_not_duplicate(char *map, char c, char *str);
int			ft_check_if_rectangle(char *buff);
int			ft_check_close_by_wall2(char *buff);
int			ft_check_close_by_wall(char *buff);
int			ft_check_if_playable(char *buff);
int			ft_put_pixel(t_mlx *mlx);
int			ft_so_long(t_mlx *mlx);
int			ft_exit_escape(int keycode, t_mlx *mlx);
int			ft_exit_cross(t_mlx *mlx);
int			ft_put_backgroud(t_mlx *mlx);
int			ft_put_wall(t_mlx *mlx);
int			ft_put_player(t_mlx *mlx);
int			ft_put_collectible(t_mlx *mlx);
int			ft_put_exit(t_mlx *mlx);
int			ft_nb_collectible(t_mlx *mlx);
int			ft_is_doable(t_mlx *mlx, int keycode);
int			ft_move_enemies(t_mlx *mlx);

void		ft_destroy_mlx(t_mlx *mlx);
void		ft_put_enemies(t_mlx *mlx);
void		ft_print_enemies(t_mlx *mlx);
void		ft_mlx_width_height_init(t_mlx *mlx);
void		ft_find_position_player(t_mlx *mlx, int *x, int *y);
void		ft_find_position_exit(t_mlx *mlx, int *x, int *y);
void		ft_parcourt_map(t_mlx *mlx, int x, int y, void *img);
void		ft_initialize_mlx(t_mlx *mlx);

char		**ft_parse_map(char *map);

#endif // !SO_LONG_H
