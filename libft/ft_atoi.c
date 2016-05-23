/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 20:46:09 by jbristhu          #+#    #+#             */
/*   Updated: 2015/10/09 23:42:49 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	int				result;
	int				isneg;

	result = 0;
	isneg = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' || \
*str == '\r' || *str == '\f')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		isneg = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && str)
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	if (isneg == 1)
		result = -result;
	return (result);
}
