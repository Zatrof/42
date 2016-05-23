/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 19:11:34 by jbristhu          #+#    #+#             */
/*   Updated: 2015/10/11 01:02:54 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	void			*mem;

	if ((mem = (void*)malloc(sizeof(*mem) * size)) == NULL)
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}
