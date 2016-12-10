/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 01:19:41 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/10 14:48:26 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "./libft/get_next_line.h"

typedef struct	s_point
{
	int			x;
	int			y;
	int			id;
}				t_point;

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
	double		pos_x;
	double		pos_y;
	int			map_pos_x;
	int			map_pos_y;
	char		collide;
	char		collide_side;
	double		ray_x; // rayPosX
	double		ray_y; // rayPosY
	double		look_x; // DirX
	double		look_y; // DirY
	int			look_x_sign;
	int			look_y_sign;
	double		dist_side_x; // Length between the player and the first edge of a map square (x axis)
	double		dist_side_y; // Same but for y axis
	double		diff_side_x; // Next length between 2 x axis
	double		diff_side_y; // Next length between 2 y axis
	double		ray_len; // Length of a ray (between player and a wall)
	int			line_start; // Start point of line (y axis)
	int			line_end; // End point of line (y axis)
}				t_player;

typedef struct	s_wrapper
{
	int			len;
	int			line_size;
	t_meta		mlx;
	t_point		*tab;
}				t_wrapper;

t_point			*ft_init_tab(char *name, int *err, int *len);

#endif
