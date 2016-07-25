/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexe_stockdata2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 19:20:36 by jbristhu          #+#    #+#             */
/*   Updated: 2016/07/24 23:09:36 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file				*annexe_rdata(char *filename, char *path, struct stat buf)
{
	t_file			*file;

	if ((file = (t_file*)malloc(sizeof(*file))) == NULL)
		return (NULL);
	if ((file->name = ft_strdup(filename)) == NULL)
		return (NULL);
	if (rstat(path, filename, &file, buf) == -1)
		return (NULL);
	if (perm(buf.st_mode, &file) == -1)
		return (NULL);
	if ((file->date = mtime(&buf.st_mtime)) == NULL)
		return (NULL);
	file->rec = NULL;
	file->path = NULL;
	file->slink = NULL;
	file->logerror = NULL;
	file->time = buf.st_mtime;
	file->size = buf.st_size;
	file->link = buf.st_nlink;
	file->block = buf.st_blocks;
	return (file);
}

char				*annexe_stockdata(char *dirname, t_llist **llist,\
	t_opts opts, DIR *dir)
{
	struct dirent	*sfile;
	char			*path;

	while ((sfile = readdir(dir)) != NULL)
	{
		path = ft_strjoin(dirname, "/");
		if (rdata(path, &(*llist), sfile->d_name, opts) == -1)
		{
			ft_putendl_fd("ERROR - ADD DATA", 2);
			return (NULL);
		}
		if (opts.rr == 1)
		{
			if (((*llist) = stockrec(*llist, path, opts)) == NULL)
			{
				ft_putendl(ft_strjoin(path, sfile->d_name));
				return (NULL);
			}
		}
	}
	return (path);
}
