/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_keyboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:36:05 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/17 21:42:53 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_move(int keycode, t_player *p)
{
	if (keycode == 13)
	{
		if (p->tab[(int)p->pos.y * p->tab_len +
			(int)(p->pos.x + p->p_dir.x / 20)].id <= 0)
			p->pos.x += p->p_dir.x / 20;
		if (p->tab[(int)(p->pos.y + p->p_dir.y / 20) *
			p->tab_len + (int)p->pos.x].id <= 0)
			p->pos.y += p->p_dir.y / 20;
	}
	if (keycode == 1)
	{
		if (p->tab[(int)p->pos.y * p->tab_len +
			(int)(p->pos.x + p->p_dir.x / 20)].id <= 0)
			p->pos.x -= p->p_dir.x / 20;
		if (p->tab[(int)(p->pos.y + p->p_dir.y / 20) *
			p->tab_len + (int)p->pos.x].id <= 0)
			p->pos.y -= p->p_dir.y / 20;
	}
}

void	ft_strafe(int keycode, t_player *p)
{
	if (keycode == 0)
	{
		if (p->tab[(int)(p->pos.y + p->p_dir.x / 20) *
			p->tab_len + (int)p->pos.x].id <= 0)
		{
			p->pos.x -= p->p_dir.y / 20;
			p->pos.y += p->p_dir.x / 20;
		}
	}
	if (keycode == 2)
	{
		if (p->tab[(int)(p->pos.y + p->p_dir.x / 20) *
			p->tab_len + (int)p->pos.x].id <= 0)
		{
			p->pos.x += p->p_dir.y / 20;
			p->pos.y -= p->p_dir.x / 20;
		}
	}
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
