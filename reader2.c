/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 21:01:02 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/07 03:33:51 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_free_list(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *lst;
	if (!*lst)
		return ;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2->content);
		free(tmp2);
	}
	*lst = NULL;
}

void	ft_set_val(t_point *tab, t_point count, int id)
{
	tab->x = count.x;
	tab->y = count.y;
	tab->id = id;
}

void	ft_free_split(char **str)
{
	int	count;

	count = 0;
	if (!str)
		return ;
	while (str[count])
	{
		free(str[count]);
		count++;
	}
	free(str);
}

void	ft_split_and_push(t_list **map, char ***tmp, char **ln, int *e)
{
	char	*tmp2;

	tmp2 = ft_epur_str(*ln);
	*tmp = ft_strsplit(tmp2, ' ');
	ft_lst_push_back(map, ft_lstnew(ft_create_tab(ft_strsplit(
		tmp2, ' '), e), ft_count_elem(*tmp) * sizeof(int)));
	free(tmp2);
}
