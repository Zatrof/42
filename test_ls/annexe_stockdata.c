/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexe_stockdata.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 17:48:53 by jbristhu          #+#    #+#             */
/*   Updated: 2016/07/19 19:42:59 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					rstat(char *path, char *filename, t_file **file, \
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

int					perm(mode_t right, t_file **file)
{
	char			*perm;

	if ((perm = ft_strnew(10)) == NULL)
		return (-1);
	perm[0] = '-';
	perm[0] = (S_ISDIR(right)) ? 'd' : perm[0];
	perm[0] = (S_ISCHR(right)) ? 'c' : perm[0];
	perm[0] = (S_ISLNK(right)) ? 'l' : perm[0];
	perm[0] = (S_ISSOCK(right)) ? 's' : perm[0];
	perm[0] = (S_ISFIFO(right)) ? 'f' : perm[0];
	perm[0] = (S_ISBLK(right)) ? 'b' : perm[0];
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

char				*mtime(time_t *t)
{
	char			*tmp;

	if ((tmp = ft_strsub(ctime(t), 4, 12)) == NULL)
		return (NULL);
	return (tmp);
}

int					rdata(char *path, t_llist **llist, char *filename, t_opts o)
{
	t_list			*list;
	t_file			*file;
	char			*temp;
	char			*b;
	struct stat		buf;

	if (lstat(ft_strjoin(path, filename), &buf) == -1)
		return (-1);
	if ((file = annexe_rdata(filename, path, buf)) == NULL)
		return (-1);
	if (o.l == 1 && file->perm[0] == 'l')
	{
		b = ft_strnew(buf.st_size);
		readlink(ft_strjoin(path, filename), b, buf.st_size + 1);
		if ((file->slink = ft_strdup(b)) == NULL)
			return (-1);
	}
	if (o.a == 1 || file->name[0] != '.')
		(*llist)->total += file->block;
	list = (*llist)->start;
	ft_lstadd(&list, ft_lstnew(file, sizeof(*file)));
	(*llist)->start = list;
	return (0);
}
