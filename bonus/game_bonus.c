/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:43:17 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/25 19:47:40 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	convert_image(t_solong *img)
{
	int	s;
	int	s1[2];
	int	f;

	s = ALL;
	s1[0] = 45;
	s1[1] = 40;
	f = 100;
	img->enms[0]
		= mlx_xpm_file_to_image(img->mlx, "textures/go_left.xpm", &s, &s);
	img->enms[1]
		= mlx_xpm_file_to_image(img->mlx, "textures/go_right.xpm", &s, &s);
	img->walls = mlx_xpm_file_to_image(img->mlx, "textures/walls1.xpm", &s, &s);
	img->p[0] = mlx_xpm_file_to_image(img->mlx, "textures/to_left.xpm", &s, &s);
	img->p[1] = mlx_xpm_file_to_image(img->mlx, "textures/to_up.xpm", &s, &s);
	img->p[2] = mlx_xpm_file_to_image(img->mlx, "textures/to_down.xpm", &s, &s);
	img->p[3]
		= mlx_xpm_file_to_image(img->mlx, "textures/to_right.xpm", &s, &s);
	img->collect
		= mlx_xpm_file_to_image(img->mlx, "textures/coll.xpm", &s1[1], &s1[1]);
	img->close = mlx_xpm_file_to_image(img->mlx, "textures/close.xpm", &f, &f);
	img->open = mlx_xpm_file_to_image(img->mlx, "textures/open.xpm", &f, &f);
	img->bg = mlx_xpm_file_to_image(img->mlx, "textures/bg.xpm", &f, &f);
	more_protaction(img);
}

void	put_img(t_solong *so_long)
{
	int	i;
	int	j;

	i = -1;
	while (++i < so_long->y)
	{
		j = 0;
		while (j < so_long->x)
		{
			if (so_long->map[i][j] == '1')
				mlx_put_image_to_window(so_long->mlx,
					so_long->mlx_win, so_long->walls, j * ALL, i * ALL);
			else if (so_long->map[i][j] == 'P')
				player_direction(so_long, i, j);
			else if (so_long->map[i][j] == 'E')
				exit_status(so_long, i, j);
			else if (so_long->map[i][j] == 'N')
				move_enmy(so_long, i, j);
			else if (so_long->map[i][j] == '0' || so_long->map[i][j] == 'C')
				put_bg_coll(so_long, i, j);
			j++;
		}
	}
}

int	key_hooks(int keycode, t_solong *v)
{
	if (keycode == 53)
		game_over(v, "<><> game over <><>\n");
	mlx_clear_window(v->mlx, v->mlx_win);
	if (keycode == 0 || keycode == 123)
		move_to_left(v);
	else if (keycode == 2 || keycode == 124)
		move_to_right(v);
	else if (keycode == 13 || keycode == 126)
		move_to_up(v);
	else if (keycode == 1 || keycode == 125)
		move_to_down(v);
	put_img(v);
	return (0);
}

int	loop_hook(t_solong *solong)
{
	static int	i;

	if (i == 15)
	{
		animation(solong);
		i = 0;
	}
	i++;
	mlx_clear_window(solong->mlx, solong->mlx_win);
	if (solong->enm.dir == 1)
		solong->enm.dir = 0;
	else
		solong->enm.dir = 1;
	put_img(solong);
	mlx_hook(solong->mlx_win, 02, 0, key_hooks, solong);
	mlx_hook(solong->mlx_win, 17, 0, ft_close_, solong);
	solong->event.move_str = ft_itoa(solong->event.move);
	mlx_string_put(solong->mlx,
		solong->mlx_win, 15, 15, 0xFFFFFFFF, solong->event.move_str);
	free(solong->event.move_str);
	solong->event.move_str = NULL;
	return (0);
}
