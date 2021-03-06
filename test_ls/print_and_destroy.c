/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:32:53 by jbristhu          #+#    #+#             */
/*   Updated: 2016/07/25 18:46:12 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				printannexe(t_file *file, int p)
{
	int				l;

	l = ft_nbrlen(file->link);
	ft_putstr(ft_strjoin(file->perm, "  "));
	while (p > l++)
		ft_putstr(" ");
	ft_putnbr(file->link);
	ft_putstr(" ");
	ft_putstr(ft_strjoin(file->user, "  "));
	ft_putstr(file->group);
}

void				printlist(t_file *file, int i, t_opts opts, int p)
{
	int				s;

	if (file->name[0] != '.' || opts.a == 1)
	{
		if (opts.l == 1)
		{
			s = ft_nbrlen(file->size);
			printannexe(file, p);
			while (i > s++)
				ft_putstr(" ");
			ft_putnbr(file->size);
			ft_putstr(" ");
			ft_putstr(file->date);
			ft_putstr(" ");
		}
		if (file->perm[0] == 'l' && file->slink != NULL && opts.l == 1)
		{
			ft_putstr(file->name);
			ft_putstr(" -> ");
			ft_putendl(file->slink);
		}
		else
			ft_putendl(file->name);
	}
}

void				total(int total)
{
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putendl("");
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
		total(llist->total);
		p = thebiggestl(llist, opts);
		i = thebiggests(llist, opts) + 2;
	}
	while (list)
	{
		f = list->content;
		if (f->name != NULL && llist->size != -1)
		{
			printlist(f, i, opts, p);
		}
		else
			ft_putendl_fd(f->logerror, 2);
		list = list->next;
	}
	llist = print_rec(opts, list, llist, f);
	destroy_list(llist);
}
