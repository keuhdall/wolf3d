/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:42:26 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/17 17:17:23 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_key_pressed(int keycode, t_player *p)
{
	p->key_pressed = keycode;
	return (0);
}

int		ft_key_released(int keycode, t_player *p)
{
	if (p->key_pressed == keycode)
		p->key_pressed = -1;
	return (0);
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
	//mlx_key_hook(p.mlx.win, &ft_manage_keyboard, &p);
	mlx_hook(p.mlx.win, 2, (1L << 0), &ft_key_pressed, &p);
	mlx_hook(p.mlx.win, 3, (1L << 1), &ft_key_released, &p);
	mlx_hook(p.mlx.win, 6, 64, &ft_rotate, &p);
	mlx_loop_hook(p.mlx.ptr, &ft_draw, &p);
	mlx_put_image_to_window(p.mlx.ptr, p.mlx.win, p.mlx.img, 0, 0);
	mlx_loop(p.mlx.ptr);
	return (0);
}
