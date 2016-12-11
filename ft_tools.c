/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 21:37:15 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/11 23:26:12 by lmarques         ###   ########.fr       */
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
	p->pos = ft_search_id(tab, tab_len, -1);
	p->look.x = -1;
	p->look.y = 0;
	p->c.screen_x = 0;
	p->c.screen_x = 0.66;
}
