/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:42:26 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/09 17:28:54 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

int		ft_get_len(t_point *tab)
{
	int	count;

	count = 0;
	while (tab[count].y == 0)
		count++;
	return (count);
}

void	ft_print_tab(t_point *tab, int len)
{
	int	count;

	count = 0;
	while (count < len)
	{
		printf("x = %d; y = %d; id = %d\n", tab[count].x, tab[count].y, tab[count].id);
		count++;
	}
}

void	ft_search_id(t_point *tab, int len, int id)
{
	int	count;

	count = 0;
	while (count < len)
	{
		if (tab[count].id == id)
			printf("x = %d; y = %d; id = %d\n", tab[count].x, tab[count].y, tab[count].id);
		count++;
	}
}

int		main(int argc, char *argv[])
{
	int		len;
	int		err;
	t_point	*tab;

	len = 0;
	err = 0;
	if (argc != 2)
	{
		ft_putendl("error");
		return (-1);
	}
	tab = ft_init_tab(argv[1], &len, &err);
	if (err == -1)
	{
		ft_putendl("error");
		return (-1);
	}
	//ft_print_tab(tab, len);
	ft_search_id(tab, len, -1);
	return (0);
}
