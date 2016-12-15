/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:36:05 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/15 18:07:20 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_rotate(int keycode, t_player *p)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = p->p_dir.x;
	oldPlaneX = p->c.screen.x;
	if (keycode == 124)
	{
		p->p_dir.x = p->p_dir.x * cos(-0.1) - p->p_dir.y * sin(-0.1);
		p->p_dir.y = oldDirX * sin(-0.1) + p->p_dir.y * cos(-0.1);
		p->c.screen.x = p->c.screen.x * cos(-0.1) - p->c.screen.y * sin(-0.1);
		p->c.screen.y = oldPlaneX * sin(-0.1) + p->c.screen.y * cos(-0.1);
	}
	if (keycode == 123)
	{
		p->p_dir.x = p->p_dir.x * cos(0.1) - p->p_dir.y * sin(0.1);
		p->p_dir.y = oldDirX * sin(0.1) + p->p_dir.y * cos(0.1);
		p->c.screen.x = p->c.screen.x * cos(0.1) - p->c.screen.y * sin(0.1);
		p->c.screen.y = oldPlaneX * sin(0.1) + p->c.screen.y * cos(0.1);
	}
	mlx_clear_window(p->mlx.ptr, p->mlx.win);
	ft_clear_image(p);
	ft_draw(p);
	mlx_put_image_to_window(p->mlx.ptr, p->mlx.win, p->mlx.img, 0, 0);
}

void	ft_move(int keycode, t_player *p)
{
	if (keycode == 126)
	{
		if (p->tab[(int)p->pos.y * ft_get_len(p->tab) +
			((int)p->pos.x + (int)p->p_dir.x)].id == 0)
			p->pos.x += p->p_dir.x;
		if (p->tab[((int)p->pos.y + (int)p->p_dir.y) *
			ft_get_len(p->tab) + (int)p->pos.x].id == 0)
			p->pos.y += p->p_dir.y;
	}
	if (keycode == 125)
	{
		if (p->tab[p->map_pos.y * ft_get_len(p->tab) +
			((int)p->pos.x + (int)p->p_dir.x)].id == 0)
			p->pos.x -= p->p_dir.x;
		if (p->tab[((int)p->pos.y + (int)p->p_dir.y) *
			ft_get_len(p->tab) + (int)p->pos.x].id == 0)
			p->pos.y -= p->p_dir.y;
	}
	mlx_clear_window(p->mlx.ptr, p->mlx.win);
	ft_clear_image(p);
	ft_draw(p);
	mlx_put_image_to_window(p->mlx.ptr, p->mlx.win, p->mlx.img, 0, 0);
}

int	ft_manage_keyboard(int keycode, t_player *p)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 123 || keycode == 124)
		ft_rotate(keycode, p);
	if (keycode == 125 || keycode == 126)
		ft_move(keycode, p);
	return (0);
}
