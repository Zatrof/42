/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stockdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 16:40:37 by jbristhu          #+#    #+#             */
/*   Updated: 2016/05/23 18:58:47 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			rstat(char *path, char *filename, t_file **file,\
	struct stat buf)
{
	struct group	*group;
	struct passwd	*passwd;

	if ((passwd = getpwuid(buf.st_uid)) == NULL)
		return (-1);
	if ((group = getgrgid(buf.st_gid)) == NULL)
		return (-1);
	if (((*file)->user = ft_strdup(passwd->pw_name)) == NULL)
		return (-1);
	if (((*file)->group = ft_strdup(group->gr_name)) == NULL)
		return (-1);
	return (0);
}

static int			perm(mode_t right, t_file **file)
{
	char			*perm;

	if ((perm = ft_strnew(10)) == NULL)
		return (-1);
	perm[0] = (right & S_IFSOCK) ? 's' : '-';
	perm[0] = (right & S_IFLNK) ? 'l' : '-';
	perm[0] = (right & S_IFBLK) ? 'b' : '-';
	perm[0] = (right & S_IFCHR) ? 'c' : '-';
	perm[0] = (right & S_IFIFO) ? 'f' : '-';
	perm[0] = (right & S_IFDIR) ? 'd' : '-';
	perm[1] = (right & S_IRUSR) ? 'r' : '-';
	perm[2] = (right & S_IWUSR) ? 'w' : '-';
	perm[3] = (right & S_IXUSR) ? 'x' : '-';
	perm[4] = (right & S_IRGRP) ? 'r' : '-';
	perm[5] = (right & S_IWGRP) ? 'w' : '-';
	perm[6] = (right & S_IXGRP) ? 'x' : '-';
	perm[7] = (right & S_IROTH) ? 'r' : '-';
	perm[8] = (right & S_IWOTH) ? 'w' : '-';
	perm[9] = (right & S_IXOTH) ? 'x' : '-';
	if (((*file)->perm = ft_strdup(perm)) == NULL)
		return (-1);
	return (0);
}

static char			*mtime(time_t *t)
{
	char			*tmp;

	if ((tmp = ft_strsub(ctime(t), 4, 12)) == NULL)
		return (NULL);
	return (tmp);
}

static int			rdata(char *path, t_llist **llist, char *filename)
{
	t_list			*list;
	t_file			*file;
	struct stat		buf;

	if ((file = (t_file*)malloc(sizeof(*file))) == NULL)
		return (-1);
	if ((file->name = ft_strdup(filename)) == NULL)
		return (-1);
	if (stat(ft_strjoin(path, filename), &buf) == -1)
		return (-1);
	if (rstat(path, filename, &file, buf) == -1)
		return (-1);
	if (perm(buf.st_mode, &file) == -1)
		return (-1);
	if ((file->date = mtime(&buf.st_mtime)) == NULL)
		return (-1);
	file->size = buf.st_size;
	file->link = buf.st_nlink;
	list = (*llist)->start;
	ft_lstadd(&list, ft_lstnew(file, sizeof(*file)));
	(*llist)->start = list;
	return (0);
}

t_llist				*stockdata(char *dirname, t_llist *llist)
{
	DIR				*dir;
	struct dirent	*sfile;

	if ((dir = opendir(dirname)) == NULL)
	{
		perror(ft_strjoin("ft_ls: ", dirname));
		return (NULL);
	}
	while ((sfile = readdir(dir)) != NULL)
	{
		if (rdata(ft_strjoin(dirname, "/"), &llist, sfile->d_name) == -1)
		{
			ft_putendl_fd("ERROR - ADD DATA", 2);
			return (NULL);
		}
	}
	if (closedir(dir) == -1)
	{
		perror(ft_strjoin("ft_ls: ", dirname));
		return (NULL);
	}
	return (llist);
}
