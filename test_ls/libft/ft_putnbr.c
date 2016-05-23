/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/02 10:49:22 by jbristhu          #+#    #+#             */
/*   Updated: 2016/01/15 19:47:08 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putnbr(int n)
{
	long			tmp;

	tmp = (long)n;
	if (tmp < 0)
	{
		ft_putchar('-');
		tmp = -tmp;
	}
	if (tmp >= 10)
	{
		ft_putnbr(tmp / 10);
		ft_putnbr(tmp % 10);
	}
	else
		ft_putchar(tmp + '0');
}
