/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 20:38:56 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/22 20:43:04 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_set_floor(t_player *p)
{
	if (p->collide_side == 'n' && p->ray_dir.x > 0)
	{
		p->floor.x = p->map_pos.x;
		p->floor.y = p->map_pos.y + p->floor.x;
	}
	else if (p->collide_side == 'n' && p->ray_dir.x < 0)
	{
		p->floor.x = p->map_pos.x + 1.0;
		p->floor.y = p->map_pos.y + p->floor.x;
	}
	else if (p->collide_side == 'y' && p->ray_dir.x > 0)
	{
		p->floor.x = p->map_pos.x + p->floor.x;
		p->floor.y = p->map_pos.y;
	}
	else
	{
		p->floor.x = p->map_pos.x + p->floor.x;
		p->floor.y = p->map_pos.y + 1.0;
	}
}
