/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hooks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:30:50 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/18 02:37:25 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_to_up(t_solong *solong)
{
	solong->direction = 'u';
	if (solong->event.y <= 0 || solong->map[solong->event.y - 1][solong->event.x] == '1')
		return ;
	if (solong->map[solong->event.y - 1][solong->event.x] == 'N')
		game_over(solong, "<><> you lost <><>\n");
	if (solong->map[solong->event.y - 1][solong->event.x] == 'E' && solong->event.collectible == 0)
	{
		solong->map[solong->event.y - 1][solong->event.x] = 'P';
		solong->map[solong->event.y--][solong->event.x] = '0';
		game_over(solong, "<><> you win <><>\n");
	}
	else if (solong->map[solong->event.y - 1][solong->event.x] == 'C')
	{
		solong->map[solong->event.y - 1][solong->event.x] = 'P';
		solong->map[solong->event.y--][solong->event.x] = '0';
		solong->event.collectible--;
	}
	else
	{
		if (solong->map[solong->event.y - 1][solong->event.x] == 'E')
			return ;
		solong->map[solong->event.y - 1][solong->event.x] = 'P';
		solong->map[solong->event.y--][solong->event.x] = '0';
	}
	solong->event.move++;
}

void	move_to_left(t_solong *solong)
{
	solong->direction = 'l';
	if (solong->event.x <= 0 || solong->map[solong->event.y][solong->event.x - 1] == '1')
		return ;
	if (solong->map[solong->event.y][solong->event.x - 1] == 'N')
		game_over(solong,"<><> you lost <><>\n");
	if (solong->map[solong->event.y][solong->event.x - 1 ] == 'E' && solong->event.collectible == 0)
	{
		solong->map[solong->event.y][solong->event.x - 1] = 'P';
		solong->map[solong->event.y][solong->event.x--] = '0';
		game_over(solong, "<><> you win <><>\n");
	}
	else if (solong->map[solong->event.y][solong->event.x - 1] == 'C')
	{
		solong->map[solong->event.y][solong->event.x - 1] = 'P';
		solong->map[solong->event.y][solong->event.x--] = '0';
		solong->event.collectible--;
	}
	else
	{
		 if (solong->map[solong->event.y][solong->event.x - 1] == 'E')
			return ;
		solong->map[solong->event.y][solong->event.x - 1] = 'P';
		solong->map[solong->event.y][solong->event.x--] = '0';
	}
	solong->event.move++;
}

void	move_to_right(t_solong *solong)
{
	solong->direction = 'r';
	if (solong->event.x >= solong->x || solong->map[solong->event.y][solong->event.x + 1] == '1')
		return ;
	if (solong->map[solong->event.y][solong->event.x + 1] == 'N')
		game_over(solong, "<><> you lost <><>\n");
	else if (solong->map[solong->event.y][solong->event.x + 1] == 'E' && solong->event.collectible == 0)
	{
		solong->map[solong->event.y][solong->event.x + 1] = 'P';
		solong->map[solong->event.y][solong->event.x++] = '0';
		game_over(solong, "<><> you win <><>\n");
	}
	else if (solong->map[solong->event.y][solong->event.x + 1] == 'C')
	{
		solong->map[solong->event.y][solong->event.x + 1] = 'P';
		solong->map[solong->event.y][solong->event.x++] = '0';
		solong->event.collectible--;
	}
	else
	{
		 if (solong->map[solong->event.y][solong->event.x + 1] == 'E')
			return ;
		solong->map[solong->event.y][solong->event.x + 1] = 'P';
		solong->map[solong->event.y][solong->event.x++] = '0';
	}
	solong->event.move++;
}

void	move_to_down(t_solong *solong)
{
	solong->direction = 'd';
	if (solong->event.y >= solong->y || solong->map[solong->event.y + 1][solong->event.x] == '1')
		return ;
	if (solong->map[solong->event.y + 1][solong->event.x] == 'N')
		game_over(solong,"<><> you lost <><>\n");
	else if (solong->map[solong->event.y + 1][solong->event.x] == 'E' && solong->event.collectible == 0)
	{
		solong->map[solong->event.y + 1][solong->event.x] = 'P';
		solong->map[solong->event.y++][solong->event.x] = '0';
		game_over(solong, "<><> you win <><>\n");
	}
	else if (solong->map[solong->event.y + 1][solong->event.x] == 'C')
	{
		solong->map[solong->event.y + 1][solong->event.x] = 'P';
		solong->map[solong->event.y++][solong->event.x] = '0';
		solong->event.collectible--;
	}
	else
	{
		 if (solong->map[solong->event.y + 1][solong->event.x] == 'E')
			return ;
		solong->map[solong->event.y + 1][solong->event.x] = 'P';
		solong->map[solong->event.y++][solong->event.x] = '0';
	}
	solong->event.move++;
}

void	game_over(t_solong *solong, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	mlx_destroy_image(solong->mlx, solong->enms[0]);
	mlx_destroy_image(solong->mlx, solong->enms[1]);
	mlx_destroy_image(solong->mlx, solong->player[0]);
	mlx_destroy_image(solong->mlx, solong->player[1]);
	mlx_destroy_image(solong->mlx, solong->player[2]);
	mlx_destroy_image(solong->mlx, solong->player[3]);
	mlx_destroy_image(solong->mlx, solong->walls);
	mlx_destroy_image(solong->mlx, solong->close);
	mlx_destroy_image(solong->mlx, solong->open);
	mlx_destroy_window(solong->mlx, solong->mlx_win);
	freememory(solong->y, solong->map);
	if (solong->event.move_str != NULL)
		free(solong->event.move_str);
	exit(0);
}
