/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 11:22:07 by jbristhu          #+#    #+#             */
/*   Updated: 2016/01/15 20:10:47 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstnew(const void *content, size_t content_size)
{
	t_list			*tmp;

	if ((tmp = (t_list*)malloc(sizeof(*tmp))) == NULL)
		return (NULL);
	if (!content)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	else
	{
		if ((tmp->content = ft_strdup((char*)content)) == NULL)
			return (NULL);
		tmp->content_size = content_size;
	}
	tmp->next = NULL;
	return (tmp);
}
