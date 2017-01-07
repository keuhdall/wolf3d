/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:22:01 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/07 19:09:29 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_check_fd(int fd)
{
	if (fd < 0)
	{
		ft_putendl("error");
		exit(1);
	}
}

void	ft_init_values(t_list **map, t_point *p, int **tmp2, char **ln)
{
	*tmp2 = NULL;
	*map = NULL;
	*ln = NULL;
	p->x = get_next_line(p->y, ln);
}
