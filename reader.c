/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 01:04:23 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/06 21:14:18 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_count_elem(char **tab)
{
	int	count;

	count = 0;
	while (tab[count] != 0)
		count++;
	return (count);
}

int		ft_parse_tab(char *line)
{
	int	count;

	count = 0;
	while (line[count])
	{
		if ((line[count] != '-' && !ft_isdigit(line[count])) ||
			line[ft_strlen(line) - 1] == '-' ||
			(count < (int)ft_strlen(line) - 1 && line[count] == '-' &&
			line[count + 1] == '-'))
			return (0);
		count++;
	}
	return (1);
}

int		*ft_create_tab(char **tmp, int *err)
{
	int		count;
	int		count2;
	int		*tab;

	count2 = 0;
	count = ft_count_elem(tmp);
	if (!(tab = (int *)malloc(sizeof(int) * count)))
		return (NULL);
	while (count2 < count)
	{
		if (!ft_parse_tab(tmp[count2]))
			*err = -1;
		tab[count2] = ft_atoi(tmp[count2]);
		count2++;
	}
	count2 = -1;
	while (++count2 < count)
		free(tmp[count2]);
	free(tmp);
	return (tab);
}

t_list	*ft_create_map(char *name, int *len, int *e)
{
	t_list	*map;
	int		ret;
	int		fd;
	char	*ln;

	map = NULL;
	fd = open(name, O_RDONLY);
	ln = NULL;
	ret = get_next_line(fd, &ln);
	*e = ret == -1 ? -1 : 0;
	if (ret < 0)
		return (NULL);
	ft_lst_push_back(&map, ft_lstnew(ft_create_tab(
		ft_strsplit(ft_epur_str(ln), ' '), e),
		ft_count_elem(ft_strsplit(ft_epur_str(ln), ' ')) * sizeof(int)));
	*len = ft_count_elem(ft_strsplit(ft_epur_str(ln), ' '));
	while ((ret = get_next_line(fd, &ln)))
	{
		ft_lst_push_back(&map, ft_lstnew(ft_create_tab(
			ft_strsplit(ft_epur_str(ln), ' '), e),
			ft_count_elem(ft_strsplit(ft_epur_str(ln), ' ')) * sizeof(int)));
		*e = ft_count_elem(ft_strsplit(ft_epur_str(ln), ' ')) != *len ? -1 : *e;
	}
	*e = (!map || !ln || len == 0 || ret == -1 || *e == -1) ? -1 : 0;
	return ((!map || !ln || len == 0 || ret == -1) ? NULL : map);
}

t_point	*ft_init_tab(char *name, int *len, int *err)
{
	t_point	count;
	t_point	*tab;
	t_list	*tmp;
	t_list	*begin;

	count.id = 0;
	count.y = 0;
	tmp = ft_create_map(name, len, err);
	begin = tmp;
	if (!(tab = (t_point *)malloc(sizeof(t_point) * *len * ft_lstsize(tmp))))
		tab = NULL;
	while (tmp)
	{
		count.x = -1;
		while (++count.x < *len)
		{
			ft_set_val(&tab[count.id], count, ((int *)(tmp->content))[count.x]);
			count.id++;
		}
		tmp = tmp->next;
		count.y++;
	}
	ft_free_list(&begin);
	*len *= count.y;
	return (tab);
}
