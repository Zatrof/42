/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 18:13:03 by jbristhu          #+#    #+#             */
/*   Updated: 2016/04/04 16:28:38 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*free_and_join(char *s1, char *s2)
{
	char			*temp;

	temp = s1;
	if ((s1 = ft_strjoin(s1, s2)) == NULL)
		return (NULL);
	ft_strdel(&temp);
	return (s1);
}
