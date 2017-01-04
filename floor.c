/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 20:38:56 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/04 02:45:38 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_set_floor(t_player *p)
{
	if (p->found_wall_side == 'n' && p->ray_dir.x > 0)
	{
		p->floor_wall.x = p->map_pos.x;
		p->floor_wall.y = p->map_pos.y + p->wall;
	}
	else if (p->found_wall_side == 'n' && p->ray_dir.x < 0)
	{
		p->floor_wall.x = p->map_pos.x + 1.0;
		p->floor_wall.y = p->map_pos.y + p->wall;
	}
	else if (p->found_wall_side == 'y' && p->ray_dir.y > 0)
	{
		p->floor_wall.x = p->map_pos.x + p->wall;
		p->floor_wall.y = p->map_pos.y;
	}
	else
	{
		p->floor_wall.x = p->map_pos.x + p->wall;
		p->floor_wall.y = p->map_pos.y + 1.0;
	}
}

void		ft_set_textures(t_player *p, t_point *tex_floor,
			t_point *tex_ceiling, t_dpoint *floor)
{
	tex_floor->x = ((int)(floor->x * p->mlx.texture[FLOOR_TEX].width)) %
	p->mlx.texture[FLOOR_TEX].width;
	tex_floor->y = ((int)(floor->y * p->mlx.texture[FLOOR_TEX].height)) %
	p->mlx.texture[FLOOR_TEX].height;
	tex_ceiling->x = (int)(floor->x * p->mlx.texture[CEILING_TEX].width) %
	p->mlx.texture[CEILING_TEX].width;
	tex_ceiling->y = (int)(floor->y * p->mlx.texture[CEILING_TEX].height) %
	p->mlx.texture[CEILING_TEX].height;
}

void		ft_set_floor_to_buffer(t_player *p, int count, t_point pt)
{
	int			*tmp;
	double		weight;
	t_point		tex_floor;
	t_point		tex_ceiling;
	t_dpoint	floor;

	pt.y = pt.y < 0 ? W_HEIGHT : pt.y;
	ft_set_floor(p);
	while (++pt.y < W_HEIGHT)
	{
		weight = (W_HEIGHT / (2.0 * pt.y - W_HEIGHT)) / p->ray_len;
		floor.x = weight * p->floor_wall.x + (1.0 - weight) * p->pos.x;
		floor.y = weight * p->floor_wall.y + (1.0 - weight) * p->pos.y;
		ft_set_textures(p, &tex_floor, &tex_ceiling, &floor);
		tmp = (int *)mlx_get_data_addr(p->mlx.texture[FLOOR_TEX].tex,
		&p->mlx.bpp, &p->mlx.size_line, &p->mlx.endian);
		p->mlx.data[pt.y * W_WIDTH + count] =
		(tmp[tex_floor.y * p->mlx.texture[FLOOR_TEX].width + tex_floor.x] >> 1)
		& 8355711;
		tmp = (int *)mlx_get_data_addr(p->mlx.texture[CEILING_TEX].tex,
		&p->mlx.bpp, &p->mlx.size_line, &p->mlx.endian);
		p->mlx.data[(W_HEIGHT - pt.y) * W_WIDTH + count] =
		tmp[p->mlx.texture[CEILING_TEX].width * tex_ceiling.y + tex_ceiling.x];
	}
}
