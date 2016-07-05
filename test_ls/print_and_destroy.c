/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 16:32:53 by jbristhu          #+#    #+#             */
/*   Updated: 2016/07/05 17:59:43 by jbristhu         ###   ########.fr       */
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
	if (opts.l == 1)
	{
		p = thebiggestl(llist, opts);
		i = thebiggests(llist, opts) + 2;
	}
	while (list)
	{
		f = list->content;
		if (f->name != NULL)
			printlist(f, i, opts, p);
		else
			ft_putendl_fd(f->logerror, 2);
		list = list->next;
	}
	//function recursive
	if (opts.rr == 1)
	{
		list = llist->start;
		while (list)
		{
			//BUG ../..
			f = list->content;
			if (f->perm[0] == 'd' && ft_strcmp(f->name, ".") != 0 && \
				ft_strcmp(f->name, "..") != 0)
			{
				ft_putendl("");
				print_and_destroy(f->rec, opts);
			}
			list = list->next;
		}
	}
	//end
	free(llist);
}
