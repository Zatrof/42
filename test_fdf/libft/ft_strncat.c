/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 19:01:42 by jbristhu          #+#    #+#             */
/*   Updated: 2016/01/03 18:14:23 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				p;

	i = 0;
	p = ft_strlen(s1);
	while (i < n && s2[i])
	{
		s1[p] = s2[i];
		p++;
		i++;
	}
	s1[p] = '\0';
	return (s1);
}
