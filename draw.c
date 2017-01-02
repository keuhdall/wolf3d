/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 20:33:59 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/31 05:14:14 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_handle_movement(t_player *p)
{
	if(ft_search_key(p, 53))
		exit(1);
	ft_move(p);
	ft_strafe(p);
}

void	ft_reset_values(t_player *p, int count)
{
	p->c.pos_x = 2 * count / (double)W_WIDTH - 1;
	p->ray_pos = p->pos;
	p->ray_dir.x = p->p_dir.x + p->c.screen.x * p->c.pos_x;
	p->ray_dir.y = p->p_dir.y + p->c.screen.y * p->c.pos_x;
	p->map_pos.x = (int)p->ray_pos.x;
	p->map_pos.y = (int)p->ray_pos.y;
	p->diff_side.x = sqrt(1 + pow(p->ray_dir.y, 2) / pow(p->ray_dir.x, 2));
	p->diff_side.y = sqrt(1 + pow(p->ray_dir.x, 2) / pow(p->ray_dir.y, 2));
	p->collide = 'n';
}

void	ft_calc_dist_side(t_player *p)
{
	if (p->ray_dir.x < 0)
	{
		p->p_dir_sign.x = -1;
		p->dist_side.x = (p->ray_pos.x - p->map_pos.x) * p->diff_side.x;
	}
	else
	{
		p->p_dir_sign.x = 1;
		p->dist_side.x = (p->map_pos.x + 1.0 - p->ray_pos.x) * p->diff_side.x;
	}
	if (p->ray_dir.y < 0)
	{
		p->p_dir_sign.y = -1;
		p->dist_side.y = (p->ray_pos.y - p->map_pos.y) * p->diff_side.y;
	}
	else
	{
		p->p_dir_sign.y = 1;
		p->dist_side.y = (p->map_pos.y + 1.0 - p->ray_pos.y) * p->diff_side.y;
	}
}

void	ft_check_collide(t_player *p)
{
	while (p->collide == 'n')
	{
		if (p->dist_side.x < p->dist_side.y)
		{
			p->dist_side.x += p->diff_side.x;
			p->map_pos.x += p->p_dir_sign.x;
			p->collide_side = 'n';
		}
		else
		{
			p->dist_side.y += p->diff_side.y;
			p->map_pos.y += p->p_dir_sign.y;
			p->collide_side = 'y';
		}
		if (p->tab[p->map_pos.y * p->tab_len + p->map_pos.x].id > 0)
			p->collide = 'y';
	}
}

int		ft_draw(t_player *p)
{
	t_point	pt;
	int		count;
	int		*tmp;

	count = -1;
	ft_clear_image(p);
	ft_handle_movement(p);
	while (++count < W_WIDTH)
	{
		ft_reset_values(p, count);
		ft_calc_dist_side(p);
		ft_check_collide(p);
		ft_calc_wall_dist(p);
		pt.x = -(W_HEIGHT / p->ray_len) / 2 + W_HEIGHT / 2;
		pt.x = pt.x < 0 ? 0 : pt.x;
		pt.y = (W_HEIGHT / p->ray_len) / 2 + W_HEIGHT / 2;
		pt.y = pt.y >= W_HEIGHT ? W_HEIGHT - 1 : pt.y;
		tmp = ft_set_tmp(p);
		ft_apply_texture(p, count, pt, tmp);
		ft_set_floor_to_buffer(p, count, pt);
	}
	mlx_put_image_to_window(p->mlx.ptr, p->mlx.win, p->mlx.img, 0, 0);
	return (0);
}
