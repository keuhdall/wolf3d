/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:16:15 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/05 17:52:25 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_check_textures(t_player *p)
{
	int	count;

	count = -1;
	while (++count <= MAX_TEX)
	{
		if (!p->mlx.texture[count].tex)
		{
			ft_putendl("Error loading textures");
			exit(1);
		}
	}
}

int		ft_get_height(t_player *p, int len)
{
	int	count;
	int	height;

	count = -1;
	height = 0;
	while (++count < len)
		height = p->tab[count].y > height ? p->tab[count].y : height;
	return (height);
}

int		ft_check_map_sides(t_player *p, int len)
{
	int	count;

	count = p->tab_len;
	while (count < len)
	{
		if (!p->tab[count].id || !p->tab[count - 1].id)
			return (1);
		count += p->tab_len;
	}
	return (0);
}

void	ft_check_map(t_player *p, int len)
{
	int	count;
	int	err;

	count = -1;
	err = 0;
	while (++count < p->tab_len)
	{
		if (!p->tab[count].id)
			err = 1;
	}
	count = p->tab_len * ft_get_height(p, len) - 2;
	while (++count < len)
	{
		if (!p->tab[count].id)
			err = 1;
	}
	if (ft_check_map_sides(p, len) || err)
	{
		ft_putendl("Error : invalid map");
		exit(1);
	}
}
