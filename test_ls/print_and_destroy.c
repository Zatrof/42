/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:32:53 by jbristhu          #+#    #+#             */
/*   Updated: 2016/07/08 16:40:38 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				printlist(t_file *file, int i, t_opts opts, int p)
{
	int				s;
	int				l;

	if (file->name[0] != '.' || opts.a == 1)
	{
		if (opts.l == 1)
		{
			s = ft_nbrlen(file->size);
			l = ft_nbrlen(file->link);
			ft_putstr(ft_strjoin(file->perm, "  "));
			while (p > l++)
				ft_putstr(" ");
			ft_putnbr(file->link);
			ft_putstr(" ");
			ft_putstr(ft_strjoin(file->user, "  "));
			ft_putstr(file->group);
			while (i > s++)
				ft_putstr(" ");
			ft_putnbr(file->size);
			ft_putstr(" ");
			ft_putstr(file->date);
			ft_putstr(" ");
		}
		ft_putendl(file->name);
	}
}

void				print_and_destroy(t_llist *llist, t_opts opts)
{
	t_list			*list;
	t_file			*f;
	int				i;
	int				p;

	list = llist->start;
	if (opts.l == 1 && llist->size != -1)
	{
		p = thebiggestl(llist, opts);
		i = thebiggests(llist, opts) + 2;
	}
	while (list)
	{
		f = list->content;
		if (f->name != NULL && llist->size != -1)
			printlist(f, i, opts, p);
		else
			ft_putendl_fd(f->logerror, 2);
		list = list->next;
	}
	llist = print_rec(opts, list, llist, f);
	free(llist);
}
