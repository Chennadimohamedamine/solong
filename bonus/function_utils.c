/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:13:02 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/28 19:04:22 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_direction(t_solong *solong, int i, int j)
{
	if (solong->direction == 'u')
		mlx_put_image_to_window(solong->mlx,
			solong->mlx_win, solong->p[1], j * ALL, i * ALL);
	else if (solong->direction == 'r')
		mlx_put_image_to_window(solong->mlx,
			solong->mlx_win, solong->p[3], j * ALL, i * ALL);
	else if (solong->direction == 'l')
		mlx_put_image_to_window(solong->mlx,
			solong->mlx_win, solong->p[0], j * ALL, i * ALL);
	else if (solong->direction == 'd')
		mlx_put_image_to_window(solong->mlx,
			solong->mlx_win, solong->p[2], j * ALL, i * ALL);
}

void	exit_status(t_solong *so_long, int i, int j)
{
	if (so_long->map[i][j] == 'E'
			&& all_collect(so_long->map) != 0)
		mlx_put_image_to_window(so_long->mlx,
			so_long->mlx_win, so_long->close, j * ALL, i * ALL);
	else if (so_long->map[i][j] == 'E'
			&& all_collect(so_long->map) == 0)
	{
		mlx_put_image_to_window(so_long->mlx,
			so_long->mlx_win, so_long->open, j * ALL, i * ALL);
		so_long->event.collectible = 0;
	}
}

void	move_enmy(t_solong *solong, int i, int j)
{
	if (solong->enm.dir == 1)
		mlx_put_image_to_window(solong->mlx, solong->mlx_win,
			solong->enms[0], j * ALL, i * ALL);
	else if (solong->enm.dir == 0)
		mlx_put_image_to_window(solong->mlx, solong->mlx_win,
			solong->enms[1], j * ALL, i * ALL);
}

void	handling_enumy(t_solong *solong)
{
	solong->enm.length_enmy = lenght_enmy(solong->map);
	if (solong->enm.length_enmy == 0)
		handling_enumy_error(solong, "you have error << need put enumy >>\n");
	else if (solong->enm.length_enmy > 4)
		handling_enumy_error(solong,
			"oops! my code dont run greater 4 enumys\n");
	get_positon_enumy(solong);
	if (valid_enumy(solong))
		handling_enumy_error(solong,
			"oops! this invalid game << becouse enumy can not move >>\n");
}

int	ft_close_(t_solong *solong)
{
	mlx_destroy_image(solong->mlx, solong->enms[0]);
	mlx_destroy_image(solong->mlx, solong->enms[1]);
	mlx_destroy_image(solong->mlx, solong->p[0]);
	mlx_destroy_image(solong->mlx, solong->p[1]);
	mlx_destroy_image(solong->mlx, solong->p[2]);
	mlx_destroy_image(solong->mlx, solong->p[3]);
	mlx_destroy_image(solong->mlx, solong->walls);
	mlx_destroy_image(solong->mlx, solong->close);
	mlx_destroy_image(solong->mlx, solong->open);
	mlx_destroy_window(solong->mlx, solong->mlx_win);
	freememory(solong->y, solong->map);
	free(solong->mlx);
	write(1, "<><>> game over <<><>\n", 22);
	if (solong->event.move_str != NULL)
		free(solong->event.move_str);
	exit(0);
}
