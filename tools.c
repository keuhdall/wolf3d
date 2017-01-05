/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 21:37:15 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/05 17:44:25 by lmarques         ###   ########.fr       */
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
			ret.x = (double)tab[count].x + 0.5;
			ret.y = (double)tab[count].y + 0.5;
			return (ret);
		}
		count++;
	}
	ft_putendl("error : could not find the given ID in the map");
	exit(1);
	return (ret);
}

void		ft_load_textures(t_player *p)
{
	p->mlx.texture[0].tex = mlx_xpm_file_to_image(p->mlx.ptr,
		"./textures/lmarques.xpm",
		&p->mlx.texture[0].width, &p->mlx.texture[0].height);
	p->mlx.texture[1].tex = mlx_xpm_file_to_image(p->mlx.ptr,
		"./textures/mossy.xpm",
		&p->mlx.texture[1].width, &p->mlx.texture[1].height);
	p->mlx.texture[2].tex = mlx_xpm_file_to_image(p->mlx.ptr,
		"./textures/wood.xpm",
		&p->mlx.texture[2].width, &p->mlx.texture[2].height);
	p->mlx.texture[3].tex = mlx_xpm_file_to_image(p->mlx.ptr,
		"./textures/redbrick.xpm",
		&p->mlx.texture[3].width, &p->mlx.texture[3].height);
	p->mlx.texture[4].tex = mlx_xpm_file_to_image(p->mlx.ptr,
		"./textures/bluestone.xpm",
		&p->mlx.texture[4].width, &p->mlx.texture[4].height);
	p->mlx.texture[5].tex = mlx_xpm_file_to_image(p->mlx.ptr,
		"./textures/colorstone.xpm",
		&p->mlx.texture[5].width, &p->mlx.texture[5].height);
	p->mlx.texture[6].tex = mlx_xpm_file_to_image(p->mlx.ptr,
		"./textures/eagle.xpm",
		&p->mlx.texture[6].width, &p->mlx.texture[6].height);
	p->mlx.texture[7].tex = mlx_xpm_file_to_image(p->mlx.ptr,
		"./textures/greystone.xpm",
		&p->mlx.texture[7].width, &p->mlx.texture[7].height);
}

void		ft_init_struct(t_player *p, t_point *tab, int tab_len)
{
	p->mlx.ptr = mlx_init();
	p->mlx.win = mlx_new_window(p->mlx.ptr, 800, 600, "wolf3d");
	p->mlx.img = mlx_new_image(p->mlx.ptr, 800, 600);
	p->mlx.data = (int *)mlx_get_data_addr(p->mlx.img, &p->mlx.bpp,
		&p->mlx.size_line, &p->mlx.endian);
	ft_load_textures(p);
	ft_check_textures(p);
	p->tab_len = ft_get_len(tab);
	p->pos = ft_search_id(tab, tab_len, -1);
	p->tab = tab;
	ft_check_map(p, tab_len);
	p->p_dir.x = -1;
	p->p_dir.y = 0;
	p->c.screen.x = 0;
	p->c.screen.y = 0.66;
	p->found_wall = 'n';
	p->found_wall_side = 'n';
	p->key_list = NULL;
}

void		ft_clear_image(t_player *p)
{
	int	count;

	count = 0;
	while (count < W_WIDTH * W_HEIGHT)
	{
		p->mlx.data[count] = 0;
		count++;
	}
}
