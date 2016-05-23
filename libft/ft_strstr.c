/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 19:04:22 by jbristhu          #+#    #+#             */
/*   Updated: 2016/01/15 20:14:20 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strstr(const char *big, const char *little)
{
	int				i;
	int				p;

	i = 0;
	if (ft_strlen(big) == 0 && ft_strlen(little) == 0)
		return ((char*)big);
	while (big[i])
	{
		p = 0;
		while (big[i] == little[p] && little[p])
		{
			p++;
			i++;
		}
		i = i - p;
		if (little[p] == '\0')
			return ((char*)big + i);
		i++;
	}
	return (NULL);
}
