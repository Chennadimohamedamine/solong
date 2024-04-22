/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:55:52 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/20 17:57:59 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(char *av)
{
	t_solong	so_long;

	so_long.map = lines(av, &so_long.y);
	so_long.x = ft_strlen(so_long.map[0]);
	so_long.mlx = mlx_init();
	so_long.mlx_win = mlx_new_window(so_long.mlx, so_long.x * ALL,
			so_long.y * ALL, "<><> so_long <><>");
	if (!so_long.map || !so_long.mlx || !so_long.mlx_win)
		return ;
	convert_img(&so_long);
	game(&so_long);
	mlx_loop(so_long.mlx);
}

int	main(int ac, char **av)
{
	if (ac != 2 || av[1] == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	so_long(av[1]);
	return (0);
}
