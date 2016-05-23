/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstde.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 11:41:41 by jbristhu          #+#    #+#             */
/*   Updated: 2015/10/11 22:22:17 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list			*lst;
	t_list			*nxtlst;

	lst = *alst;
	while (lst)
	{
		nxtlst = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = nxtlst;
	}
	*alst = NULL;
}
