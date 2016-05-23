/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 18:26:47 by jbristhu          #+#    #+#             */
/*   Updated: 2016/01/03 18:30:19 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char				*ft_strrchr(const char *s, int c)
{
	size_t			len;
	char			ch;

	len = ft_strlen(s) + 1;
	ch = (char)c;
	while (len-- != 0)
	{
		if (s[len] == ch)
			return ((char*)s + len);
	}
	return (NULL);
}
