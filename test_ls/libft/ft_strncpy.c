/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 18:54:52 by jbristhu          #+#    #+#             */
/*   Updated: 2015/10/09 21:22:43 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncpy(char *dst, const char *src, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (!src[i])
		{
			while (i < n)
			{
				dst[i] = 0;
				i++;
			}
		}
		else
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
