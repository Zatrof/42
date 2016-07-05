/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:35:24 by jbristhu          #+#    #+#             */
/*   Updated: 2016/07/05 19:25:47 by jbristhu         ###   ########.fr       */
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
	return (llist);
}

int					main(int ac, char **av)
{
	int				i;
	t_opts			opts;
	t_llist			*llist;
	int				test;

	i = detect_opts(ac, av, &opts);
	test = 0;
	while (i < ac || test == 0)
	{
		if ((llist = initllist(llist)) == NULL)
			return (1);
		if ((llist = stockdata(((i == ac) ? "." : av[i]), llist)) == NULL)
			return (1);
		i++;
		llist = sortfile(llist, opts);
		print_and_destroy(llist, opts);
		test = 1;
	}
	return (0);
}
