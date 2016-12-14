/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:36:05 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/14 23:27:38 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	ft_manage_keyboard(int keycode, t_player *p)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 124) // Right
	{
		double oldDirX = p->p_dir.x;
		p->p_dir.x = p->p_dir.x * cos(-1) - p->p_dir.y * sin(-1);
		p->p_dir.y = oldDirX * sin(-1) + p->p_dir.y * cos(-1);
		double oldPlaneX = p->c.screen.x;
		p->c.screen.x = p->c.screen.x * cos(-1) - p->c.screen.x * sin(-1);
		p->c.screen.x = oldPlaneX * sin(-1) + p->c.screen.x * cos(-1);
		mlx_clear_window(p->mlx.ptr, p->mlx.win);
		ft_reset_map(p);
		ft_draw(p);
		mlx_put_image_to_window(p->mlx.ptr, p->mlx.win, p->mlx.img, 0, 0);
	}
	if (keycode == 123) // Left
	{
		double oldDirX = p->p_dir.x;
		p->p_dir.x = p->p_dir.x * cos(1) - p->p_dir.y * sin(1);
		p->p_dir.y = oldDirX * sin(1) + p->p_dir.y * cos(1);
		double oldPlaneX = p->c.screen.x;
		p->c.screen.x = p->c.screen.x * cos(1) - p->c.screen.x * sin(1);
		p->c.screen.x = oldPlaneX * sin(1) + p->c.screen.x * cos(0.1);
		mlx_clear_window(p->mlx.ptr, p->mlx.win);
		ft_reset_map(p);
		ft_draw(p);
		mlx_put_image_to_window(p->mlx.ptr, p->mlx.win, p->mlx.img, 0, 0);
	}
	return (0);
}
