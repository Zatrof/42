/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stockdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 16:40:37 by jbristhu          #+#    #+#             */
/*   Updated: 2016/07/24 23:09:14 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_llist		*test_ex(char *dirname, t_llist *llist, t_opts o)
{
	DIR				*dir;
	struct dirent	*sfile;
	int				test;

	test = 0;
	if ((dir = opendir(".")) == NULL)
	{
		ft_putendl_fd("ERROR - OPENDIR", 2);
		return (NULL);
	}
	while ((sfile = readdir(dir)) != NULL)
	{
		if (ft_strcmp(dirname, sfile->d_name) == 0)
		{
			test = 1;
			if (rdata(ft_strjoin(".", "/"), &llist, sfile->d_name, o) == -1)
			{
				ft_putendl_fd("ERROR - ADD DATA", 2);
				return (NULL);
			}
		}
	}
	if (test == 0)
		llist = NULL;
	return (llist);
}

t_llist				*stockrec(t_llist *llist, char *path, t_opts opts)
{
	t_list			*tmp;
	t_file			*test;

	tmp = llist->start;
	test = tmp->content;
	if (test->perm[0] == 'd' && ft_strcmp(test->name, ".") != 0 && \
		ft_strcmp(test->name, "..") != 0)
	{
		if ((test->rec = initllist(test->rec)) == NULL)
			return (NULL);
		if ((test->path = ft_strjoin(path, test->name)) == NULL)
			return (NULL);
		if ((test->rec = stockdata(test->path, test->rec, opts)) == NULL)
		{
			ft_putendl_fd("ERROR - ADD DATA", 2);
			return (NULL);
		}
	}
	return (llist);
}

static t_llist		*logerror(char *dirname, t_llist *llist)
{
	t_file			*file;
	t_list			*tmp;

	if ((file = (t_file*)malloc(sizeof(*file))) == NULL)
		return (NULL);
	if ((file->logerror = ft_strjoin(ft_strjoin("ft_ls: ", dirname),\
		": No such file or directory")) == NULL)
		return (NULL);
	file->name = NULL;
	if ((llist = initllist(llist)) == NULL)
		return (NULL);
	if ((llist->start = ft_lstnew(file, sizeof(*file))) == NULL)
		return (NULL);
	llist->size = -1;
	return (llist);
}

t_llist				*stockdata(char *dirname, t_llist *llist, t_opts opts)
{
	DIR				*dir;
	struct dirent	*sfile;
	char			*path;

	if ((dir = opendir(dirname)) == NULL)
	{
		if ((llist = test_ex(dirname, llist, opts)) != NULL)
			return (llist);
		if ((llist = logerror(dirname, llist)) == NULL)
			return (NULL);
		return (llist);
	}
	if ((path = annexe_stockdata(dirname, &llist, opts, dir)) == NULL)
		return (NULL);
	if (closedir(dir) == -1)
	{
		perror(ft_strjoin("ft_ls: ", dirname));
		return (NULL);
	}
	return (llist);
}
