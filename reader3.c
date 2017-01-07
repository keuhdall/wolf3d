/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:22:01 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/07 16:25:59 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_values(t_list **map, t_point *p, int **tmp2, char **ln)
{
	*tmp2 = NULL;
	*map = NULL;
	*ln = NULL;
	p->x = get_next_line(p->y, ln);
}
