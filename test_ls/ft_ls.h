/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:36:06 by jbristhu          #+#    #+#             */
/*   Updated: 2016/06/08 10:54:32 by jbristhu         ###   ########.fr       */
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
	int				size;
	int				link;
	long			time;
}					t_file;

typedef struct		s_llist
{
	t_list			*start;
	int				size;
}					t_llist;

int					detect_opts(int ac, char **av, t_opts *opts);
t_llist				*stockdata(char *dirname, t_llist *llist);
t_llist				*sortfile(t_llist *llist, t_opts opts);
void				print_and_destroy(t_llist *llist, t_opts opts);

#endif
