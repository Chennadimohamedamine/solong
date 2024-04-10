/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:46:50 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/10 22:15:45 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void convert_img_(t_solong *img)
{
    int s[2];

    s[0] = ALL;
    s[1] = 100;
    img->walls = mlx_xpm_file_to_image(img->mlx,"img/walls1.xpm",&s[0],&s[0]);
    img->player[0] = mlx_xpm_file_to_image(img->mlx,"img/player_left.xpm",&s[0],&s[0]);
    img->player[1] = mlx_xpm_file_to_image(img->mlx,"img/player_up.xpm",&s[0],&s[0]);
    img->player[2] = mlx_xpm_file_to_image(img->mlx,"img/player_down.xpm",&s[0],&s[0]);
    img->player[3] = mlx_xpm_file_to_image(img->mlx,"img/player_.xpm",&s[0],&s[0]);
    img->collect = mlx_xpm_file_to_image(img->mlx,"img/collectible.xpm",&s[0],&s[0]);
    img->close = mlx_xpm_file_to_image(img->mlx,"img/close.xpm",&s[1],&s[1]);
    img->open = mlx_xpm_file_to_image(img->mlx,"img/open.xpm",&s[1],&s[1]);
    img->bg = mlx_xpm_file_to_image(img->mlx,"img/bg.xpm",&s[1],&s[1]);
    img->enmy_[0] = mlx_xpm_file_to_image(img->mlx,"img/go_left.xpm",&s[0],&s[0]);
    img->enmy_[1] = mlx_xpm_file_to_image(img->mlx,"img/go_left.xpm",&s[0],&s[0]);
}
void player_direction(t_solong *solong, int i, int j)
{
    if (solong->direction == 'u')
        mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->player[1], j * ALL, i * ALL);
    else if (solong->direction == 'r')
        mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->player[3], j * ALL, i * ALL);
    else if (solong->direction == 'l')
        mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->player[0], j * ALL, i * ALL);
    else if (solong->direction == 'd')
        mlx_put_image_to_window(solong->mlx, solong->mlx_win,solong->player[2], j * ALL, i * ALL);
}
int	key_hook(int keycode, t_solong *v)
{
    // print_move(v->event.move++);
    mlx_clear_window(v->mlx,v->mlx_win);
    if (keycode == 53)
        ft_close(v);
    else if(keycode == 0 || keycode == 123)
        move_to_left(v);
    else if(keycode == 2 || keycode == 124)
        move_to_right(v);
    else if(keycode == 13 || keycode == 126)
        move_to_up(v);
    else if(keycode == 1 || keycode == 125)
        move_to_down(v);
    put_img(v);
	return (0);
}
int	loop_hook(t_solong *solong)
{
    int i = 0;
    while( i < 50)
            i++;
    mlx_key_hook(solong->mlx_win, &key_hook, solong);
    //     printf("hey 1 \n");

    // put_image(v);
	return (0);
}