/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 18:04:02 by jbristhu          #+#    #+#             */
/*   Updated: 2016/05/11 17:26:13 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int					end(int i, char **tmp, char ***line, int ret)
{
	if (ret == 0)
	{
		ft_strdel(tmp);
		return (0);
	}
	if (i == -1)
		i = ft_strlen(*tmp);
	if ((**line = copy_line(&tmp, i)) == NULL)
		return (-1);
	return (1);
}

int					get_next_line(int fd, char **line)
{
	char			buf[BUFF_SIZE];
	static char		*tmp;
	char			*temp;
	int				ret;
	int				i;

	if (!tmp)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		if ((tmp = ft_strsub(buf, 0, ret)) == NULL)
			return (-1);
	}
	while ((i = detect_line(tmp)) == -1 && ret != 0)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		if ((temp = ft_strsub(buf, 0, ret)) == NULL)
			return (-1);
		if ((tmp = free_and_join(tmp, temp)) == NULL)
			return (-1);
		ft_strdel(&temp);
	}
	return (end(i, &tmp, &line, ret));
}
