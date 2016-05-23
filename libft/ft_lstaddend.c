/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:27:13 by jbristhu          #+#    #+#             */
/*   Updated: 2016/05/19 16:28:52 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstaddend(t_list **alst, t_list *new)
{
	if (alst != NULL && new != NULL)
	{
		(*alst)->next = new;
		new->next = NULL;
		(*alst) = new;
	}
}
