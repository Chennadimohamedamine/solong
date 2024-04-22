/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:04:37 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/23 00:24:10 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_bonus(t_solong *solong)
{
	int	dir[2];

	dir[0] = 0;
	dir[1] = 0;
	get_positon(solong->map, &dir[0], &dir[1]);
	solong->event.y = dir[0];
	solong->event.x = dir[1];
	get_positon_exit(solong->map, &solong->y_e, &solong->x_e);
	solong->enm.dir = 0;
	solong->enm.e_dir[0] = 0;
	solong->direction = 'r';
	solong->event.move = 0;
	make_enmy(solong);
	check_validgame(solong);
	solong->event.collectible = all_collect(solong->map);
	convert_image(solong);
	put_img(solong);
	mlx_loop_hook(solong->mlx, &loop_hook, solong);
}

void	so_long_bonus(char *av)
{
	t_solong	so_long;

	so_long.map = lines(&so_long, av, &so_long.y);
	if (!so_long.map)
		return ;
	so_long.x = ft_strlen(so_long.map[0]);
	so_long.mlx = mlx_init();
	so_long.mlx_win = mlx_new_window(so_long.mlx,
			so_long.x * ALL, so_long.y * ALL, "<><> so_long <><>");
	if (!so_long.map || !so_long.mlx || !so_long.mlx_win)
		return ;
	game_bonus(&so_long);
	mlx_loop(so_long.mlx);
}

int	main(int ac, char **av)
{
	if (ac != 2 || av[1] == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	so_long_bonus(av[1]);
	return (0);
}
