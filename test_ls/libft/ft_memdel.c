/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/25 19:14:14 by jbristhu          #+#    #+#             */
/*   Updated: 2015/10/10 00:00:19 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_memdel(void **ap)
{
	free(*ap);
	*ap = NULL;
}
