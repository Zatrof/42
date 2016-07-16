/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:35:24 by jbristhu          #+#    #+#             */
/*   Updated: 2016/07/16 22:56:59 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_llist				*initllist(t_llist *llist)
{
	if ((llist = (t_llist*)malloc(sizeof(*llist))) == NULL)
	{
		ft_putendl_fd("ERROR - INIT LIST", 2);
		return (NULL);
	}
	llist->start = NULL;
	llist->size = 0;
	llist->total = 0;
	return (llist);
}

int					main(int ac, char **av)
{
	int				i;
	t_opts			opts;
	t_llist			*llist;
	int				test;

	if ((i = detect_opts(ac, av, &opts)) == -1)
		return (1);
	test = 0;
	while (i < ac || test == 0)
	{
		if ((llist = initllist(llist)) == NULL)
			return (1);
		if ((llist = stockdata(((i == ac) ? "." : av[i]), llist, opts)) == NULL)
			return (1);
		if (llist->size != -1)
			llist = sortfile(llist, opts);
		if ((i + 1 < ac || test == 1) && llist->size != -1)
			ft_putendl(ft_strjoin(av[i], ":"));
		print_and_destroy(llist, opts);
		if (i + 1 < ac && llist->size != -1)
			ft_putendl("");
		i++;
		test = 1;
	}
	return (0);
}
