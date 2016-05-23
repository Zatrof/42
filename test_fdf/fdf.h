/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:46:02 by jbristhu          #+#    #+#             */
/*   Updated: 2016/05/10 17:57:05 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct          s_pos
{
    int                 x;
    int                 y;
    int                 z;
    void                *nxt;
}                       t_pos;

#endif
