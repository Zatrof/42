/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexe_print_and_destroy.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 15:57:01 by jbristhu          #+#    #+#             */
/*   Updated: 2016/07/25 19:50:46 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list				*freelist(t_list *tmp, t_file *file)
{
	t_list			*l;

	l = tmp;
	free(file);
	tmp = tmp->next;
	l = NULL;
	return (tmp);
}

void				destroy_list(t_llist *llist)
{
	t_list			*tmp;
	t_file			*file;

	tmp = llist->start;
	while (tmp)
	{
		file = tmp->content;
		ft_strdel(&file->name);
		ft_strdel(&file->perm);
		ft_strdel(&file->user);
		ft_strdel(&file->group);
		ft_strdel(&file->date);
		ft_strdel(&file->logerror);
		if (file->path)
			ft_strdel(&file->path);
		if (file->slink)
			ft_strdel(&file->slink);
		if (file->rec)
			destroy_list(file->rec);
		tmp = freelist(tmp, file);
	}
	tmp = NULL;
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
		if (f->name[0] != '.' || opts.a == 1)
		{
			if (ft_nbrlen(f->size) > i)
				i = ft_nbrlen(f->size);
		}
		tmp = tmp->next;
	}
	return (i);
}

t_llist				*print_rec(t_opts opts, t_list *list, t_llist *llist, \
	t_file *f)
{
	if (opts.rr == 1 && llist->size != -1)
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
