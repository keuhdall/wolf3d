/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 01:19:41 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/11 23:22:29 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h> // ATTENTION !!
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
}				t_meta;

typedef struct	s_camera
{
	double		pos_x;
	double		screen_x;
	double		screen_y;
}				t_camera;

typedef struct	s_player
{
	t_point		*tab;
	t_camera	c;
	t_dpoint	pos;
	t_point		map_pos;
	t_dpoint	ray; //rayPos
	t_dpoint	look; //Dir
	t_point		look_sign;
	t_dpoint	dist_side; // Length between the player and the first edge of a map square
	t_dpoint	diff_side; // Next length between 2 axis
	double		ray_len; // Length of a ray (between player and a wall)
	int			line_start; // Start point of line (y axis)
	int			line_end; // End point of line (y axis)
	char		collide;
	char		collide_side;
}				t_player;

typedef struct	s_wrapper
{
	int			len;
	int			line_size;
	t_meta		mlx;
	t_point		*tab;
}				t_wrapper;

t_point			*ft_init_tab(char *name, int *err, int *len);
t_dpoint		ft_search_id(t_point *tab, int len, int id);

#endif
