/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbristhu <jbristhu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 16:45:36 by jbristhu          #+#    #+#             */
/*   Updated: 2016/05/10 18:24:05 by jbristhu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				key_hook(int keycode, void *mlx)
{
	(void)mlx;
	if (keycode == 53)
		exit(1);
	ft_putnbr(keycode);
	ft_putendl("");
	return (0);
}

int				main(int ac, char **av)
{
	void		*mlx;
	void		*win;
	int			fd;
	int			ret;
	char		*line;

	if (ac != 2)
	{
		ft_putendl_fd("ERROR - NO MAP ENTRY", 2);
		return (1);
	}
	if ((fd = open(av[1], 0)) == -1)
	{
		ft_putendl_fd("ERROR - OPEN MAP", 2);
		return (1);
	}
	while ((ret = get_next_line(fd, &line)) != 0)
	{
		if (ret == -1)
		{
			ft_putendl_fd("ERROR - GET_NEXT_LINE", 2);
			return (1);
		}
		
	}
	mlx = mlx_init();
	if ((win = mlx_new_window(mlx, 500, 500, "test_fdf")) == NULL)
	{
		ft_putendl_fd("ERROR - OPEN WINDOW", 2);
		return (1);
	}
	mlx_key_hook(win, key_hook, &mlx);
	mlx_loop(mlx);
	return (0);
}
