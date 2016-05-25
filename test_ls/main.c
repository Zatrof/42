/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:35:24 by jbristhu          #+#    #+#             */
/*   Updated: 2016/05/25 18:41:59 by jbristhu         ###   ########.fr       */
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
	print_and_destroy(llist, opts);
	return (0);
}
