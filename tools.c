/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 21:37:15 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/12 17:12:43 by lmarques         ###   ########.fr       */
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
			ret.x = (double)tab[count].x;
			ret.y = (double)tab[count].y;
			return (ret);
		}
		count++;
	}
	ft_putendl("error : could not find the given ID in the map");
	ret.x = -1;
	ret.y = -1;
	return (ret);
}

void		ft_init_struct(t_player *p, t_point *tab, int tab_len)
{
	p->mlx.ptr = mlx_init();
	p->mlx.win = mlx_new_window(p->mlx.ptr, 800, 600, "wolf3d");
	p->mlx.img = mlx_new_image(p->mlx.ptr, 800, 600);
	p->mlx.data = (int *)mlx_get_data_addr(p->mlx.img, &p->mlx.bpp,
		&p->mlx.size_line, &p->mlx.endian);
	p->pos = ft_search_id(tab, tab_len, -1);
	p->p_dir.x = -1;
	p->p_dir.y = 0;
	p->c.screen.x = 0;
	p->c.screen.y = 0.66;
	p->collide = 'n';
	p->collide_side = 'n';
}

void		ft_reset_values(t_player *p, int count)
{
	p->c.pos_x = 2 * count / W_WIDTH - 1;
	p->ray_pos = p->pos;
	p->ray_dir.x = p->p_dir.x + p->c.screen.x * p->c.pos_x;
	p->ray_dir.y = p->p_dir.y + p->c.screen.y * p->c.pos_x;
	p->map_pos.x = (int)p->ray_pos.x;
	p->map_pos.y = (int)p->ray_pos.y;
	p->diff_side.x = sqrt(1 + pow(p->ray_dir.y, 2) / pow(p->ray_dir.x, 2));
	p->diff_side.y = sqrt(1 + pow(p->ray_dir.x, 2) / pow(p->ray_dir.y, 2));
	p->collide = 'n';
}

void		ft_draw(t_player *p)
{
	int	count;

	count = 0;
	while (count < W_WIDTH)
	{
		ft_reset_values(p, count);
		count++;
	}
}
