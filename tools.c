/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 21:37:15 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/17 17:38:45 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_get_len(t_point *tab)
{
	int	count;

	count = 0;
	while (tab[count].y == 0)
		count++;
	return (count);
}

t_dpoint	ft_search_id(t_point *tab, int len, int id)
{
	int			count;
	t_dpoint	ret;

	count = 0;
	while (count < len)
	{
		if (tab[count].id == id)
		{
			ret.x = (double)tab[count].x + 1;
			ret.y = (double)tab[count].y + 1;
			return (ret);
		}
		count++;
	}
	ft_putendl("error : could not find the given ID in the map");
	ret.x = -1;
	ret.y = -1;
	return (ret);
}

void		ft_trace_vline(int x, int y1, int y2, t_player *p)
{
	t_point	tab[2];
	int		err;
	int		e2;

	tab[0].x = 0;
	tab[0].y = abs(y2 - y1);
	tab[1].x = -1;
	tab[1].y = y1 < y2 ? 1 : -1;
	err = (tab[0].x > tab[0].y ? tab[0].x : tab[0].y) / 2;
	while (1)
	{
		p->mlx.data[y1 * W_WIDTH + 1 + x] = p->color;
		if (y1 == y2)
			break ;
		e2 = err;
		if (e2 > -tab[0].x)
			err -= tab[0].y;
		if (e2 > -tab[0].x)
			x += tab[1].x;
		if (e2 < tab[0].y)
			err += tab[0].x;
		if (e2 < tab[0].y)
			y1 += tab[1].y;
	}
}

void		ft_init_struct(t_player *p, t_point *tab, int tab_len)
{
	p->mlx.ptr = mlx_init();
	p->mlx.win = mlx_new_window(p->mlx.ptr, 800, 600, "wolf3d");
	p->mlx.img = mlx_new_image(p->mlx.ptr, 800, 600);
	p->mlx.data = (int *)mlx_get_data_addr(p->mlx.img, &p->mlx.bpp,
		&p->mlx.size_line, &p->mlx.endian);
	p->pos = ft_search_id(tab, tab_len, -1);
	tab_len++;
	p->tab = tab;
	p->p_dir.x = -1;
	p->p_dir.y = 0;
	p->c.screen.x = 0;
	p->c.screen.y = 0.66;
	p->collide = 'n';
	p->collide_side = 'n';
	p->key_pressed = -1;
}

void		ft_check_collide(t_player *p)
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
		if (p->tab[p->map_pos.y * ft_get_len(p->tab) + p->map_pos.x].id > 0)
			p->collide = 'y';
	}
}

void		ft_calc_dist_side(t_player *p)
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

void		ft_set_color(t_player *p)
{
	if (p->tab[p->map_pos.y * ft_get_len(p->tab) + p->map_pos.x].id == 1)
		p->color = 0xFF0000;
	else if (p->tab[p->map_pos.y * ft_get_len(p->tab) + p->map_pos.x].id == 2)
		p->color = 0x00FF00;
	else if (p->tab[p->map_pos.y * ft_get_len(p->tab) + p->map_pos.x].id == 3)
		p->color = 0x0000FF;
	else if (p->tab[p->map_pos.y * ft_get_len(p->tab) + p->map_pos.x].id == 4)
		p->color = 0xFFFFFF;
	else
		p->color = 0xFFFF00;
	if (p->collide_side == 'y')
		p->color /= 2;
}

void		ft_reset_values(t_player *p, int count)
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

void		ft_clear_image(t_player *p)
{
	int	count;

	count = 0;
	while (count < 800 * 600)
	{
		p->mlx.data[count] = 0;
		count++;
	}
}

void		ft_handle_movement(t_player *p)
{
	if (p->key_pressed == 53)
		exit(1);
	ft_move(p->key_pressed, p);
	ft_strafe(p->key_pressed, p);
}

int			ft_draw(t_player *p)
{
	int	count;
	int	start;
	int	end;

	count = 0;
	ft_clear_image(p);
	ft_handle_movement(p);
	while (count < W_WIDTH)
	{
		ft_reset_values(p, count);
		ft_calc_dist_side(p);
		ft_check_collide(p);
		if (p->collide_side == 'n')
			p->ray_len = (p->map_pos.x - p->ray_pos.x +
				(1 - p->p_dir_sign.x) / 2) / p->ray_dir.x;
		else
			p->ray_len = (p->map_pos.y - p->ray_pos.y +
				(1 - p->p_dir_sign.y) / 2) / p->ray_dir.y;
		start = -(W_HEIGHT / p->ray_len) / 2 + W_HEIGHT / 2;
		start = start < 0 ? 0 : start;
		end = (W_HEIGHT / p->ray_len) / 2 + W_HEIGHT / 2;
		end = end >= W_HEIGHT ? W_HEIGHT - 1 : end;
		ft_set_color(p);
		ft_trace_vline(count, start, end, p);
		count++;
	}
	mlx_put_image_to_window(p->mlx.ptr, p->mlx.win, p->mlx.img, 0, 0);
	return (0);
}
