/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 21:37:15 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/21 05:50:03 by lmarques         ###   ########.fr       */
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

void		ft_load_textures(t_player *p)
{
	p->mlx.texture[0].tex = mlx_xpm_file_to_image(p->mlx.ptr,
		"/Users/lmarques/Desktop/lmarques.xpm",
		&p->mlx.texture[0].width, &p->mlx.texture[0].height);
	p->mlx.texture[1].tex = mlx_xpm_file_to_image(p->mlx.ptr,
		"/Users/lmarques/Desktop/wood.xpm",
		&p->mlx.texture[1].width, &p->mlx.texture[1].height);
	p->mlx.texture[2].tex = mlx_xpm_file_to_image(p->mlx.ptr,
		"/Users/lmarques/Desktop/perfection.xpm",
		&p->mlx.texture[2].width, &p->mlx.texture[2].height);
}

void		ft_init_struct(t_player *p, t_point *tab, int tab_len)
{
	p->mlx.ptr = mlx_init();
	p->mlx.win = mlx_new_window(p->mlx.ptr, 800, 600, "wolf3d");
	p->mlx.img = mlx_new_image(p->mlx.ptr, 800, 600);
	p->mlx.data = (int *)mlx_get_data_addr(p->mlx.img, &p->mlx.bpp,
		&p->mlx.size_line, &p->mlx.endian);
	ft_load_textures(p);
	p->pos = ft_search_id(tab, tab_len, -1);
	p->tab_len = ft_get_len(tab);
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
		if (p->tab[p->map_pos.y * p->tab_len + p->map_pos.x].id > 0)
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
	if (p->tab[p->map_pos.y * p->tab_len + p->map_pos.x].id == 1)
		p->color = 0xFF0000;
	else if (p->tab[p->map_pos.y * p->tab_len + p->map_pos.x].id == 2)
		p->color = 0x00FF00;
	else if (p->tab[p->map_pos.y * p->tab_len + p->map_pos.x].id == 3)
		p->color = 0x0000FF;
	else if (p->tab[p->map_pos.y * p->tab_len + p->map_pos.x].id == 4)
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

void		ft_calc_wall_dist(t_player *p)
{
	if (p->collide_side == 'n')
		p->ray_len = (p->map_pos.x - p->ray_pos.x +
			(1 - p->p_dir_sign.x) / 2) / p->ray_dir.x;
	else
		p->ray_len = (p->map_pos.y - p->ray_pos.y +
			(1 - p->p_dir_sign.y) / 2) / p->ray_dir.y;
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

void		ft_apply_texture(t_player *p, int count, int start, int end, int *tmp)
{
	int		id;
	int		d;
	double	wall;
	t_point	tex;

	id = p->tab[p->map_pos.y * p->tab_len + p->map_pos.x].id - 1;
	wall = p->collide_side == 'n' ? p->ray_pos.y + p->ray_len * p->ray_dir.y :
		p->ray_pos.x + p->ray_len * p->ray_dir.x;
	wall -= floor((wall));
	tex.x = (int)(wall * (double)p->mlx.texture[id].width);
	if (p->collide_side == 'n' && p->ray_dir.x > 0)
		tex.x = p->mlx.texture[id].width - tex.x - 1;
	if (p->collide_side == 'y' && p->ray_dir.x < 0)
		tex.x = p->mlx.texture[id].width - tex.x - 1;
	while (start < end)
	{
		d = start * 256 - W_HEIGHT * 128 + (int)(W_HEIGHT / p->ray_len) * 128;
		tex.y = ((d * p->mlx.texture[id].height) /
			(int)(W_HEIGHT / p->ray_len)) / 256;
		p->mlx.data[start * W_WIDTH + count] = tmp[p->mlx.texture[id].height *
			tex.y + tex.x];
		start++;
	}
}

int			ft_draw(t_player *p)
{
	t_point	pt;
	int		count;
	int		*tmp;

	count = 0;
	ft_clear_image(p);
	ft_handle_movement(p);
	while (count < W_WIDTH)
	{
		ft_reset_values(p, count);
		ft_calc_dist_side(p);
		ft_check_collide(p);
		ft_calc_wall_dist(p);
		pt.x = -(W_HEIGHT / p->ray_len) / 2 + W_HEIGHT / 2;
		pt.x = pt.x < 0 ? 0 : pt.x;
		pt.y = (W_HEIGHT / p->ray_len) / 2 + W_HEIGHT / 2;
		pt.y = pt.y >= W_HEIGHT ? W_HEIGHT - 1 : pt.y;
		tmp = (int *)mlx_get_data_addr(p->mlx.texture[p->tab[p->map_pos.y *
			p->tab_len + p->map_pos.x].id - 1].tex,
			&p->mlx.bpp, &p->mlx.size_line, &p->mlx.endian);
		ft_apply_texture(p, count, pt.x, pt.y, tmp);
		count++;
	}
	mlx_put_image_to_window(p->mlx.ptr, p->mlx.win, p->mlx.img, 0, 0);
	return (0);
}
