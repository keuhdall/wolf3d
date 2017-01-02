/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 22:05:35 by lmarques          #+#    #+#             */
/*   Updated: 2017/01/02 16:36:33 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_key_list	*ft_new_key(int keycode, char state)
{
	t_key_list *tmp;

	if (!(tmp = (t_key_list *)malloc(sizeof(t_key_list))))
		return (NULL);
	tmp->key.keycode = keycode;
	tmp->key.state = state;
	tmp->next = NULL;
	return (tmp);
}

void		ft_push_key(t_key_list **list, t_key_list *new)
{
	t_key_list	*tmp;

	tmp = NULL;
	tmp = *list;
	if (!tmp)
		*list = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void		ft_parse_keys_press(t_player *p, int keycode)
{
	t_key_list	*tmp;

	tmp = NULL;
	tmp = p->key_list;
	while (tmp && tmp->key.keycode != keycode)
		tmp = tmp->next;
	if (tmp)
		tmp->key.state = 1;
	else
		ft_push_key(&p->key_list, ft_new_key(keycode, 1));
}

void		ft_parse_keys_release(t_player *p, int keycode)
{
	t_key_list	*tmp;

	tmp = NULL;
	tmp = p->key_list;
	while (tmp && tmp->key.keycode != keycode)
		tmp = tmp->next;
	if (tmp)
		tmp->key.state = 0;
	else
		ft_push_key(&p->key_list, ft_new_key(keycode, 1));
}

char		ft_search_key(t_player *p, int keycode)
{
	t_key_list	*tmp;

	tmp = NULL;
	tmp = p->key_list;
	while (tmp)
	{
		if (tmp->key.keycode == keycode)
			return (tmp->key.state ? 1 : 0);
		tmp = tmp->next;
	}
	return (0);
}
