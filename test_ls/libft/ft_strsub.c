/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 20:22:31 by jbristhu          #+#    #+#             */
/*   Updated: 2015/10/11 01:03:22 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s)
	{
		if ((str = ft_strnew(len)) == NULL)
			return (NULL);
		while (i < len)
		{
			str[i] = s[start];
			i++;
			start++;
		}
		return (str);
	}
	return (NULL);
}
