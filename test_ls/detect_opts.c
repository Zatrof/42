/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_opts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:05:08 by jbristhu          #+#    #+#             */
/*   Updated: 2016/07/18 12:12:47 by jbristhu         ###   ########.fr       */
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

t_opts				*testopts(char c, t_opts *opts)
{
	if (c == 'a')
		opts->a = 1;
	else if (c == 'l')
		opts->l = 1;
	else if (c == 'r')
		opts->r = 1;
	else if (c == 't')
		opts->t = 1;
	else if (c == 'R')
		opts->rr = 1;
	else
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(c, 2);
		ft_putendl("");
		ft_putendl_fd("usage: ft_ls [-Ralrt] [file ...]", 2);
		return (NULL);
	}
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
			if ((opts = testopts(av[i][t], opts)) == NULL)
				return (-1);
			t++;
		}
		i++;
	}
	return (i);
}
