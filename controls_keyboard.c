/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_keyboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:36:05 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/24 01:53:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_move(t_player *p)
{
	if (ft_search_key(p, 13))
	{
		if (p->tab[(int)p->pos.y * p->tab_len +
			(int)(p->pos.x + p->p_dir.x / 20)].id <= 0)
			p->pos.x += p->p_dir.x / 20;
		if (p->tab[(int)(p->pos.y + p->p_dir.y / 20) *
			p->tab_len + (int)p->pos.x].id <= 0)
			p->pos.y += p->p_dir.y / 20;
	}
	if (ft_search_key(p, 1))
	{
		if (p->tab[(int)p->pos.y * p->tab_len +
			(int)(p->pos.x + p->p_dir.x / 20)].id <= 0)
			p->pos.x -= p->p_dir.x / 20;
		if (p->tab[(int)(p->pos.y + p->p_dir.y / 20) *
			p->tab_len + (int)p->pos.x].id <= 0)
			p->pos.y -= p->p_dir.y / 20;
	}
}

void	ft_strafe(t_player *p)
{
	if (ft_search_key(p, 0))
	{
		if (p->tab[(int)(p->pos.y + p->p_dir.x / 20) *
			p->tab_len + (int)p->pos.x].id <= 0)
		{
			p->pos.x -= p->p_dir.y / 20;
			p->pos.y += p->p_dir.x / 20;
		}
	}
	if (ft_search_key(p, 2))
	{
		if (p->tab[(int)(p->pos.y + p->p_dir.x / 20) *
			p->tab_len + (int)p->pos.x].id <= 0)
		{
			p->pos.x += p->p_dir.y / 20;
			p->pos.y -= p->p_dir.x / 20;
		}
	}
}
