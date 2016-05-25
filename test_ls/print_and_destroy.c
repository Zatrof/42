/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:32:53 by jbristhu          #+#    #+#             */
/*   Updated: 2016/05/25 18:40:18 by jbristhu         ###   ########.fr       */
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

int					thebiggest(t_llist *llist)
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

void				printlist(t_file *file, int i, t_opts opts)
{
	int				s;

	if (file->name[0] != '.' || opts.a == 1)
	{
		s = ft_nbrlen(file->size);
		ft_putstr(file->perm);
		ft_putstr("  ");
		ft_putnbr(file->link);
		ft_putstr(" ");
		ft_putstr(file->user);
		ft_putstr("  ");
		ft_putstr(file->group);
		while (i > s)
		{
			ft_putstr(" ");
			s++;
		}
		ft_putnbr(file->size);
		ft_putstr(" ");
		ft_putstr(file->date);
		ft_putstr(" ");
		ft_putstr(file->name);
		ft_putendl("");
	}
}

void				print_and_destroy(t_llist *llist, t_opts opts)
{
	t_list			*list;
	t_list			*tmp;
	t_file			*f;
	int				i;

	list = llist->start;
	i = thebiggest(llist) + 2;
	while (list)
	{
		f = list->content;
		printlist(f, i, opts);
		tmp = list->next;
		destroy(list);
		list = tmp;
	}
	free(llist);
}
