/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enamy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:47:47 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/23 00:08:36 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	go_to_up(t_solong *solong, int i, int *y, int *x)
{
	if (solong->map[*y - 1][*x] == 'C' || solong->map[*y - 1][*x] == 'N'
		|| solong->map[*y - 1][*x] == 'E' || solong->map[*y - 1][*x] == '1')
	{
		solong->enm.e_dir[i] = 1;
		return ;
	}
	else if (solong->map[*y - 1][*x] == 'P')
	{
		solong->map[*y - 1][*x] = 'N';
		solong->map[*y--][*x] = '0';
		game_over(solong, "<><> you lost <><>\n");
	}
	solong->map[*y - 1][*x] = 'N';
	solong->map[*y][*x] = '0';
	*y -= 1;
}

void	go_to_down(t_solong *solong, int i, int *y, int *x)
{
	if (solong->map[*y + 1][*x] == 'C' || solong->map[*y + 1][*x] == 'N'
		|| solong->map[*y + 1][*x] == 'E' || solong->map[*y + 1][*x] == '1')
	{
		solong->enm.e_dir[i] = 0;
		return ;
	}
	else if (solong->map[*y + 1][*x] == 'P')
	{
		solong->map[*y + 1][*x] = 'N';
		solong->map[*y++][*x] = '0';
		game_over(solong, "<><> you lost <><>\n");
	}
	solong->map[*y + 1][*x] = 'N';
	solong->map[*y][*x] = '0';
	*y += 1;
}

void	go_to_left(t_solong *solong, int i, int *y, int *x)
{
	if (solong->map[*y][*x - 1] == 'C' || solong->map[*y][*x - 1] == 'N'
		|| solong->map[*y][*x - 1] == 'E' || solong->map[*y][*x - 1] == '1')
	{
		solong->enm.e_dir[i] = 3;
		return ;
	}
	else if (solong->map[*y][*x - 1] == 'P')
	{
		solong->map[*y][*x - 1] = 'N';
		solong->map[*y][*x] = '0';
		game_over(solong, "<><> you lost <><>\n");
	}
	solong->map[*y][*x - 1] = 'N';
	solong->map[*y][*x] = '0';
	*x -= 1;
}

void	go_to_right(t_solong *solong, int i, int *y, int *x)
{
	if (solong->map[*y][*x + 1] == 'C' || solong->map[*y][*x + 1] == 'N'
		|| solong->map[*y][*x + 1] == 'E' || solong->map[*y][*x + 1] == '1')
	{
		solong->enm.e_dir[i] = 2;
		return ;
	}
	else if (solong->map[*y][*x + 1] == 'P')
	{
		solong->map[*y][*x + 1] = 'N';
		solong->map[*y][*x] = '0';
		game_over(solong, "<><> you lost <><>\n");
	}
	solong->map[*y][*x + 1] = 'N';
	solong->map[*y][*x] = '0';
	*x += 1;
}
