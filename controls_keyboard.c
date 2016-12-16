/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_keyboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:36:05 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/16 03:58:17 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_move(int keycode, t_player *p)
{
	if (keycode == 13)
	{
		if (p->tab[(int)p->pos.y * ft_get_len(p->tab) +
			((int)p->pos.x + (int)p->p_dir.x)].id == 0)
			p->pos.x += p->p_dir.x;
		if (p->tab[((int)p->pos.y + (int)p->p_dir.y) *
			ft_get_len(p->tab) + (int)p->pos.x].id == 0)
			p->pos.y += p->p_dir.y;
	}
	if (keycode == 1)
	{
		if (p->tab[(int)p->pos.y * ft_get_len(p->tab) +
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

void	ft_strafe(int keycode, t_player *p)
{
	if (keycode == 0)
	{
		if (p->tab[((int)p->pos.y + (int)p->p_dir.x) *
			ft_get_len(p->tab) + (int)p->pos.x].id == 0)
		{
			p->pos.x -= p->p_dir.y;
			p->pos.y += p->p_dir.x;
		}
	}
	if (keycode == 2)
	{
		if (p->tab[((int)p->pos.y + (int)p->p_dir.x) *
			ft_get_len(p->tab) + (int)p->pos.x].id == 0)
		{
			p->pos.x += p->p_dir.y;
			p->pos.y -= p->p_dir.x;
		}
	}
	mlx_clear_window(p->mlx.ptr, p->mlx.win);
	ft_clear_image(p);
	ft_draw(p);
	mlx_put_image_to_window(p->mlx.ptr, p->mlx.win, p->mlx.img, 0, 0);
}

int		ft_manage_keyboard(int keycode, t_player *p)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 13 || keycode == 1)
		ft_move(keycode, p);
	if (keycode == 2 || keycode == 0)
		ft_strafe(keycode, p);
	return (0);
}
