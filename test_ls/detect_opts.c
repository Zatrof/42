/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_opts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:05:08 by jbristhu          #+#    #+#             */
/*   Updated: 2016/07/16 23:05:57 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_opts		*new_opts(t_opts *opts)
{
	opts->a = 0;
	opts->l = 0;
	opts->r = 0;
	opts->t = 0;
	opts->rr = 0;
	return (opts);
}

int					detect_opts(int ac, char **av, t_opts *opts)
{
	int				i;
	int				t;

	i = 1;
	opts = new_opts(opts);
	while (i < ac && av[i][0] == '-')
	{
		t = 1;
		while (av[i][t])
		{
			if (av[i][t] == 'a')
				opts->a = 1;
			else if (av[i][t] == 'l')
				opts->l = 1;
			else if (av[i][t] == 'r')
				opts->r = 1;
			else if (av[i][t] == 't')
				opts->t = 1;
			else if (av[i][t] == 'R')
				opts->rr = 1;
			else
			{
				ft_putstr_fd("ft_ls: illegal option -- ", 2);
				ft_putchar_fd(av[i][t], 2);
				ft_putendl("");
				ft_putstr_fd("usage: ft_ls [-ABCFGHLOPRSTUWabcde", 2);
				ft_putendl_fd("fghiklmnopqrstuwx1] [file ...]", 2);
				return (-1);
			}
			t++;
		}
		i++;
	}
	return (i);
}
