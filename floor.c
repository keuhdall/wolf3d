/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 20:38:56 by lmarques          #+#    #+#             */
/*   Updated: 2016/12/30 18:46:22 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_set_floor(t_player *p)
{
	if (p->collide_side == 'n' && p->ray_dir.x > 0)
	{
		p->floor_wall.x = p->map_pos.x;
		p->floor_wall.y = p->map_pos.y + p->floor_wall.x;
	}
	else if (p->collide_side == 'n' && p->ray_dir.x < 0)
	{
		p->floor_wall.x = p->map_pos.x + 1.0;
		p->floor_wall.y = p->map_pos.y + p->floor_wall.x;
	}
	else if (p->collide_side == 'y' && p->ray_dir.x > 0)
	{
		p->floor_wall.x = p->map_pos.x + p->floor_wall.x;
		p->floor_wall.y = p->map_pos.y;
	}
	else
	{
		p->floor_wall.x = p->map_pos.x + p->floor_wall.x;
		p->floor_wall.y = p->map_pos.y + 1.0;
	}
}
/*
void	ft_set_floor_to_buffer(t_player *p, int count, t_point pt)
{
	int			*tmp;
	double		distWall, distPlayer, currentDist;
	t_point		tex_floor;
	//t_point		tex_ceiling;
	t_dpoint	floor;

	distWall = p->ray_len;
	distPlayer = 0.0;
	pt.y = pt.y < 0 ? W_HEIGHT : pt.y;
	ft_set_floor(p);
	while (++pt.y < W_HEIGHT)
	{
		currentDist = W_HEIGHT / (2.0 * pt.y - W_HEIGHT);
		double weight = (currentDist - distPlayer) / (distWall - distPlayer);
		floor.x = weight * p->floor_wall.x + (1.0 - weight) *
		p->pos.x;
		floor.y = weight * p->floor_wall.y + (1.0 - weight) *
		p->pos.y;
		tex_floor.x = ((int)(floor.x * p->mlx.texture[0].width)) %
		p->mlx.texture[0].width;
		tex_floor.y = ((int)(floor.y * p->mlx.texture[0].height)) %
		p->mlx.texture[0].height;
		
		//tex_ceiling.x = (int)(floor.x * p->mlx.texture[1].width) %
		//p->mlx.texture[1].width;
		//tex_ceiling.y = (int)(floor.y * p->mlx.texture[1].height) %
		//p->mlx.texture[1].height;
		

		tmp = (int *)mlx_get_data_addr(p->mlx.texture[0].tex,
		&p->mlx.bpp, &p->mlx.size_line, &p->mlx.endian);

		p->mlx.data[pt.y * W_WIDTH + count] =
		(tmp[tex_floor.y * p->mlx.texture[0].width + tex_floor.x] >> 1)
		& 8355711;

		//tmp = (int *)mlx_get_data_addr(p->mlx.texture[1].tex,
		//&p->mlx.bpp, &p->mlx.size_line, &p->mlx.endian);

		//p->mlx.data[(W_HEIGHT - y) * W_WIDTH + count] =
		//tmp[p->mlx.texture[1].width * tex_ceiling.y + tex_ceiling.x];
	}
}
*/

void	ft_set_floor_to_buffer(t_player *p, int count, t_point pt)
{
	double distWall, distPlayer, currentDist;

	//int	*tmp = (int *)mlx_get_data_addr(p->mlx.texture[2].tex,
	//&p->mlx.bpp, &p->mlx.size_line, &p->mlx.endian);
	distWall = p->ray_len;
	distPlayer = 0.0;

	if (pt.y < 0)
		pt.y = W_HEIGHT; //becomes < 0 when the integer overflows

	for (int y = pt.y + 1; y < W_HEIGHT; y++)
	{
		currentDist = W_HEIGHT / (2.0 * y - W_HEIGHT); //you could make a small lookup table for this instead
		double weight = (currentDist - distPlayer) / (distWall - distPlayer);
		double currentFloorX = weight * p->floor_wall.x + (1.0 - weight) * p->pos.x;
		double currentFloorY = weight * p->floor_wall.y + (1.0 - weight) * p->pos.y;
		int floorTexX, floorTexY;
		floorTexX = (int)(currentFloorX * p->mlx.texture[2].width) % p->mlx.texture[2].width;
		floorTexY = (int)(currentFloorY * p->mlx.texture[2].height) % p->mlx.texture[2].height;
		//buffer[y][x] = (texture[3][texWidth * floorTexY + floorTexX] >> 1) & 8355711;
		p->mlx.data[y * W_WIDTH + count] = 0x0000FF;
		//tmp[p->mlx.texture[2].width * floorTexY + floorTexX];
		//(tmp[p->mlx.texture[2].width * floorTexY + floorTexX] >> 1) & 8355711;
		//buffer[h - y][x] = texture[6][texWidth * floorTexY + floorTexX];
	}
}
