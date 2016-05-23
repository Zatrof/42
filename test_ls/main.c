/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:35:24 by jbristhu          #+#    #+#             */
/*   Updated: 2016/05/23 18:41:48 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_llist		*initllist(t_llist *llist)
{
	if ((llist = (t_llist*)malloc(sizeof(*llist))) == NULL)
		return (NULL);
	llist->start = NULL;
	llist->size = 0;
	return (llist);
}

void				testprint(t_llist *llist, t_opts opts)
{
	t_list			*l;
	t_file			*tmp;
	char			*a;

	l = llist->start;
	while (l)
	{
		tmp = l->content;
		if (opts.a != 1 && tmp->name[0] == '.')
			l = l->next;
		else
		{
			ft_putstr(tmp->perm);
			ft_putstr(" ");
			ft_putnbr(tmp->link);
			ft_putstr(" ");
			ft_putstr(tmp->user);
			ft_putstr(" ");
			ft_putstr(tmp->group);
			ft_putstr(" ");
			ft_putnbr(tmp->size);
			ft_putstr(" ");
			ft_putstr(tmp->date);
			ft_putstr(" ");
			ft_putendl(tmp->name);
			l = l->next;
		}
	}
}

int					main(int ac, char **av)
{
	int				i;
	t_opts			opts;
	t_llist			*llist;
	int				test;

	if ((llist = initllist(llist)) == NULL)
	{
		ft_putendl_fd("ERROR - INIT LIST", 2);
		return (1);
	}
	i = detect_opts(ac, av, &opts);
	test = 0;
	while (i < ac || test == 0)
	{
		test = 1;
		if ((llist = stockdata(((i == ac) ? "." : av[i]), llist)) == NULL)
			return (1);
		i++;
	}
	llist = sortfile(llist, opts);
	testprint(llist, opts);
	//print_and_destroy
	return (0);
}
