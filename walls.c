/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 20:10:49 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/22 20:16:16 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		*ft_set_tmp(t_player *p)
{
	int	id;
	int	*tmp;

	id = p->tab[p->map_pos.y * p->tab_len + p->map_pos.x].id - 1;
	id = id < 0 ? 0 : id;
	id = id > 2 ? 2 : id;
	tmp = (int *)mlx_get_data_addr(p->mlx.texture[id].tex, &p->mlx.bpp,
		&p->mlx.size_line, &p->mlx.endian);
	return (tmp);
}

void	ft_apply_texture(t_player *p, int count, t_point pt, int *tmp)
{
	int		id;
	int		d;
	double	wall;
	t_point	tex;

	id = p->tab[p->map_pos.y * p->tab_len + p->map_pos.x].id - 1;
	id = id < 0 ? 0 : id;
	id = id > 2 ? 2 : id;
	wall = p->collide_side == 'n' ? p->ray_pos.y + p->ray_len * p->ray_dir.y :
		p->ray_pos.x + p->ray_len * p->ray_dir.x;
	wall -= floor((wall));
	tex.x = (int)(wall * (double)p->mlx.texture[id].width);
	if (p->collide_side == 'n' && p->ray_dir.x > 0)
		tex.x = p->mlx.texture[id].width - tex.x - 1;
	if (p->collide_side == 'y' && p->ray_dir.x < 0)
		tex.x = p->mlx.texture[id].width - tex.x - 1;
	while (pt.x < pt.y)
	{
		d = pt.x * 256 - W_HEIGHT * 128 + (int)(W_HEIGHT / p->ray_len) * 128;
		tex.y = ((d * p->mlx.texture[id].height) /
			(int)(W_HEIGHT / p->ray_len)) / 256;
		p->mlx.data[pt.x * W_WIDTH + count] = tmp[p->mlx.texture[id].height *
			tex.y + tex.x];
		pt.x++;
	}
}

void	ft_calc_wall_dist(t_player *p)
{
	if (p->collide_side == 'n')
		p->ray_len = (p->map_pos.x - p->ray_pos.x +
			(1 - p->p_dir_sign.x) / 2) / p->ray_dir.x;
	else
		p->ray_len = (p->map_pos.y - p->ray_pos.y +
			(1 - p->p_dir_sign.y) / 2) / p->ray_dir.y;
}
