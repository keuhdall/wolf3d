/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 01:19:41 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/07 16:21:12 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include "./libft/get_next_line.h"

typedef struct	s_meta
{
	void		*ptr;
	void		*win;
	void		*img;
}				t_meta;

typedef struct	s_point
{
	int			x;
	int			y;
	int			id;
}				t_point;

typedef struct	s_wrapper
{
	int			len;
	int			line_size;
	t_meta		mlx;
	t_point		*tab;
}				t_wrapper;

t_point			*ft_init_tab(char *name, int *err, int *len);

#endif
