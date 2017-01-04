/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_keyboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:36:05 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/04 19:22:52 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_move(t_player *p)
{
	int	s;

	s = ft_search_key(p, 257) ? SPEED / 3 : SPEED;
	if (ft_search_key(p, 13))
	{
		if (p->tab[(int)p->pos.y * p->tab_len +
			(int)(p->pos.x + p->p_dir.x / s)].id <= 0)
			p->pos.x += p->p_dir.x / s;
		if (p->tab[(int)(p->pos.y + p->p_dir.y / s) *
			p->tab_len + (int)p->pos.x].id <= 0)
			p->pos.y += p->p_dir.y / s;
	}
	if (ft_search_key(p, 1))
	{
		if (p->tab[(int)p->pos.y * p->tab_len +
			(int)(p->pos.x - p->p_dir.x / s)].id <= 0)
			p->pos.x -= p->p_dir.x / s;
		if (p->tab[(int)(p->pos.y - p->p_dir.y / s) *
			p->tab_len + (int)p->pos.x].id <= 0)
			p->pos.y -= p->p_dir.y / s;
	}
}

void	ft_strafe(t_player *p)
{
	int	s;

	s = ft_search_key(p, 257) ? SPEED / 3 : SPEED;
	if (ft_search_key(p, 0))
	{
		if (p->tab[(int)(p->pos.y + p->p_dir.x / s) *
			p->tab_len + (int)(p->pos.x - p->p_dir.y / s)].id <= 0)
		{
			p->pos.x -= p->p_dir.y / s;
			p->pos.y += p->p_dir.x / s;
		}
	}
	if (ft_search_key(p, 2))
	{
		if (p->tab[(int)(p->pos.y - p->p_dir.x / s) *
			p->tab_len + (int)(p->pos.x + p->p_dir.y / s)].id <= 0)
		{
			p->pos.x += p->p_dir.y / s;
			p->pos.y -= p->p_dir.x / s;
		}
	}
}
