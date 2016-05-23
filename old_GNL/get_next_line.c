/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 18:04:02 by jbristhu          #+#    #+#             */
/*   Updated: 2016/05/02 16:47:39 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					detect_line(char *str)
{
	int				cur;

	cur = 0;
	while (str[cur])
	{
		if (str[cur] == '\n')
			return (cur);
		cur++;
	}
	return (-1);
}

char				*copy_line(char ***tmp, int i)
{
	char			*line;
	char			*temp;

	temp = **tmp;
	if ((line = ft_strsub(**tmp, 0, i)) == NULL)
		return (NULL);
	i++;
	if ((**tmp = ft_strsub(**tmp, i, ft_strlen(**tmp) - i)) == NULL)
		return (NULL);
	ft_strdel(&temp);
	return (line);
}

int					end(int i, char **tmp, char ***line)
{
	if (i == -1)
		i = ft_strlen(*tmp);
	if ((**line = copy_line(&tmp, i)) == NULL)
		return (-1);
	return (1);
}

int					nameless(int fd, char *buf, char **tmp)
{
	char			*temp;
	int				ret;

	if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	if ((temp = ft_strsub(buf, 0, ret)) == NULL)
		return (-1);
	if ((*tmp = free_and_join(*tmp, temp)) == NULL)
		return (-1);
	ft_strdel(&temp);
	return (ret);
}

int					get_next_line(int fd, char **line)
{
	char			buf[BUFF_SIZE];
	static char		*tmp;
	int				ret;
	int				i;

	if (!tmp)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		if ((tmp = ft_strsub(buf, 0, ret)) == NULL)
			return (-1);
	}
	while ((i = detect_line(tmp)) == -1)
	{
		if ((ret = nameless(fd, buf, &tmp)) == -1)
			return (-1);
		if (ret == 0)
		{
			ft_strdel(&tmp);
			return (0);
		}
	}
	return (end(i, &tmp, &line));
}
