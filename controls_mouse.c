/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 03:54:38 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/20 19:41:14 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	ft_rotate(int x, int y, t_player *p)
{
	static int	old_x = 400;
	double		old_dir_x;
	double		old_screen_x;

	old_dir_x = p->p_dir.x;
	old_screen_x = p->c.screen.x;
	p->p_dir.x = x > old_x ? p->p_dir.x * cos(-0.05) - p->p_dir.y *
	sin(-0.05) : p->p_dir.x * cos(0.05) - p->p_dir.y * sin(0.05);
	p->p_dir.y = x > old_x ? old_dir_x * sin(-0.05) + p->p_dir.y *
	cos(-0.05) : old_dir_x * sin(0.05) + p->p_dir.y * cos(0.05);
	p->c.screen.x = x > old_x ? p->c.screen.x * cos(-0.05) - p->c.screen.y *
	sin(-0.05) : p->c.screen.x * cos(0.05) - p->c.screen.y * sin(0.05);
	p->c.screen.y = x > old_x ? old_screen_x * sin(-0.05) + p->c.screen.y *
	cos(-0.05) : old_screen_x * sin(0.05) + p->c.screen.y * cos(0.05);
	old_x = x + (y - y);
	mlx_clear_window(p->mlx.ptr, p->mlx.win);
	ft_clear_image(p);
	ft_draw(p);
	mlx_put_image_to_window(p->mlx.ptr, p->mlx.win, p->mlx.img, 0, 0);
	return (0);
}
