/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 19:21:32 by jbristhu          #+#    #+#             */
/*   Updated: 2016/01/15 20:13:47 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	p;

	i = 0;
	if (ft_strlen(s1) == 0 && ft_strlen(s2) == 0)
		return ((char*)s1);
	while (s1[i] && i < n)
	{
		p = 0;
		while (s1[i] == s2[p] && s2[p] && i < n)
		{
			p++;
			i++;
		}
		i = i - p;
		if (s2[p] == '\0')
			return ((char*)s1 + i);
		i++;
	}
	return (NULL);
}
