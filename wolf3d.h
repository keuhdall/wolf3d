/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 01:19:41 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/17 16:34:49 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h> // ATTENTION !!
# include <math.h>
# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "./libft/get_next_line.h"

# define W_WIDTH 800
# define W_HEIGHT 600

typedef struct	s_point
{
	int			x;
	int			y;
	int			id;
}				t_point;

typedef struct	s_dpoint
{
	double		x;
	double		y;
}				t_dpoint;

typedef struct	s_meta
{
	void		*ptr;
	void		*win;
	void		*img;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_meta;

typedef struct	s_camera
{
	double		pos_x;
	t_dpoint	screen;
}				t_camera;

typedef struct	s_player
{
	t_point		*tab;
	int			tab_len;
	t_meta		mlx;
	t_camera	c;
	t_dpoint	pos;
	t_point		map_pos;
	t_dpoint	ray_pos;
	t_dpoint	ray_dir;
	t_dpoint	p_dir; //Dir
	t_point		p_dir_sign;
	t_dpoint	dist_side; // Length between the player and the first edge of a map square
	t_dpoint	diff_side; // Next length between 2 axis
	double		ray_len; // Length of a ray (between player and a wall)
	int			line_start; // Start point of line (y axis)
	int			line_end; // End point of line (y axis)
	char		collide;
	char		collide_side;
	int			color;
	char		key_pressed;
}				t_player;

int				ft_get_len(t_point *tab);
void			ft_init_struct(t_player *p, t_point *tab, int tab_len);
void			ft_clear_image(t_player *p);
int				ft_draw(t_player *p);
int				ft_manage_keyboard(int keycode, t_player *p);
int				ft_rotate(int x, int y, t_player *p);
void			ft_move(int keycode, t_player *p);
void			ft_strafe(int keycode, t_player *p);
t_point			*ft_init_tab(char *name, int *err, int *len);
t_dpoint		ft_search_id(t_point *tab, int len, int id);

#endif
