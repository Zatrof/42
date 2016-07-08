/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:36:06 by jbristhu          #+#    #+#             */
/*   Updated: 2016/07/08 15:58:46 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <time.h>
# include <grp.h>
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>

typedef struct		s_opts
{
	int				l;
	int				a;
	int				r;
	int				t;
	int				rr;
}					t_opts;

typedef struct		s_file
{
	char			*perm;
	char			*name;
	char			*user;
	char			*group;
	char			*date;
	char			*logerror;
	int				size;
	int				link;
	long			time;
	char			*path;
	struct s_llist	*rec;
}					t_file;

typedef struct		s_llist
{
	t_list			*start;
	int				size;
}					t_llist;

void				destroy(t_list *list);
int					thebiggestl(t_llist *llist, t_opts opts);
int					thebiggests(t_llist *llist, t_opts opts);
t_llist				*print_rec(t_opts opts, t_list *list, t_llist *llist, \
	t_file *f);
int					rdata(char *path, t_llist **llist, char *filename);
char				*mtime(time_t *t);
int					perm(mode_t right, t_file **file);
int					rstat(char *path, char *filename, t_file **file, \
	struct stat buf);
int					detect_opts(int ac, char **av, t_opts *opts);
t_llist				*stockdata(char *dirname, t_llist *llist);
t_llist				*sortfile(t_llist *llist, t_opts opts);
void				print_and_destroy(t_llist *llist, t_opts opts);
t_llist				*initllist(t_llist *llist);

#endif
