/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:36:05 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/14 20:26:03 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	ft_manage_keyboard(int keycode, t_player *p)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 124)
	{
		double oldDirX = p->p_dir.x;
		p->p_dir.x = p->p_dir.x * cos(-0.2) - p->p_dir.y * sin(-0.2);
		p->p_dir.y = oldDirX * sin(-0.2) + p->p_dir.y * cos(-0.2);
		double oldPlaneX = p->c.screen.x;
		p->c.screen.x = p->c.screen.x * cos(-0.2) - p->c.screen.x * sin(-0.2);
		p->c.screen.x = oldPlaneX * sin(-0.2) + p->c.screen.x * cos(-0.2);
		mlx_clear_window(p->mlx.ptr, p->mlx.win);
		ft_draw(p);
		mlx_put_image_to_window(p->mlx.ptr, p->mlx.win, p->mlx.img, 0, 0);
	}
	if (keycode == 123)
	{
		double oldDirX = p->p_dir.x;
		p->p_dir.x = p->p_dir.x * cos(0.2) - p->p_dir.y * sin(0.2);
		p->p_dir.y = oldDirX * sin(0.2) + p->p_dir.y * cos(0.2);
		double oldPlaneX = p->c.screen.x;
		p->c.screen.x = p->c.screen.x * cos(0.2) - p->c.screen.x * sin(0.2);
		p->c.screen.x = oldPlaneX * sin(0.2) + p->c.screen.x * cos(0.2);
		mlx_clear_window(p->mlx.ptr, p->mlx.win);
		ft_draw(p);
		mlx_put_image_to_window(p->mlx.ptr, p->mlx.win, p->mlx.img, 0, 0);
	}
	return (0);
}
