/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexe_print_and_destroy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:57:01 by jbristhu          #+#    #+#             */
/*   Updated: 2016/07/08 16:10:55 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				destroy(t_list *list)
{
	t_file			*tmp;

	tmp = list->content;
	ft_strdel(&tmp->perm);
	ft_strdel(&tmp->name);
	ft_strdel(&tmp->user);
	ft_strdel(&tmp->group);
	ft_strdel(&tmp->date);
	free(list);
}

int					thebiggestl(t_llist *llist, t_opts opts)
{
	int				i;
	t_file			*f;
	t_list			*tmp;

	i = 0;
	tmp = llist->start;
	while (tmp)
	{
		f = tmp->content;
		if (f->name[0] != '.' || opts.a == 1)
		{
			if (ft_nbrlen(f->link) > i)
				i = ft_nbrlen(f->link);
		}
		tmp = tmp->next;
	}
	return (i);
}

int					thebiggests(t_llist *llist, t_opts opts)
{
	int				i;
	t_file			*f;
	t_list			*tmp;

	i = 0;
	tmp = llist->start;
	while (tmp)
	{
		f = tmp->content;
		if (ft_nbrlen(f->size) > i)
			i = ft_nbrlen(f->size);
		tmp = tmp->next;
	}
	return (i);
}

t_llist				*print_rec(t_opts opts, t_list *list, t_llist *llist, \
	t_file *f)
{
	if (opts.rr == 1)
	{
		list = llist->start;
		while (list)
		{
			f = list->content;
			if (f->perm[0] == 'd' && ft_strcmp(f->name, ".") != 0 && \
				ft_strcmp(f->name, "..") != 0)
			{
				ft_putendl("");
				ft_putendl(free_and_join(f->path, ":"));
				print_and_destroy(f->rec, opts);
			}
			list = list->next;
		}
	}
	return (llist);
}
