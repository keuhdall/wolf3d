/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:42:26 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/12 20:25:57 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

int		main(int argc, char *argv[])
{
	int			len;
	int			err;
	t_point		*tab;
	t_player	p;

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
	ft_init_struct(&p, tab, len);
	ft_draw(&p);
	mlx_put_image_to_window(p.mlx.ptr, p.mlx.win, p.mlx.img, 0, 0);
	mlx_loop(p.mlx.ptr);
	return (0);
}
