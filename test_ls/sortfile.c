/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 17:18:33 by jbristhu          #+#    #+#             */
/*   Updated: 2016/06/15 17:41:28 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			comparecontent(t_file *cont1, t_file *cont2, t_opts opts)
{
	if (opts.t == 1)
	{
		if (opts.r == 1)
			return (cont1->time - cont2->time);
		return ((cont1->time - cont2->time) * -1);
	}
	if (opts.r == 1)
		return (ft_strcmp(cont1->name, cont2->name) * -1);
	return (ft_strcmp(cont1->name, cont2->name));
}

t_llist				*sortfile(t_llist *llist, t_opts opts)
{
	t_file			*tmp;
	t_list			*tmp1;
	t_list			*tmp2;
	int				swap;
	int				i;

	swap = 1;
	while (swap != 0)
	{
		swap = 0;
		tmp1 = llist->start;
		while (tmp1->next != NULL)
		{
			tmp2 = tmp1->next;
			if (comparecontent(tmp1->content, tmp2->content, opts) > 0)
			{
				swap = 1;
				tmp = tmp1->content;
				tmp1->content = tmp2->content;
				tmp2->content = tmp;
			}
			tmp1 = tmp1->next;
		}
	}
	return (llist);
}
