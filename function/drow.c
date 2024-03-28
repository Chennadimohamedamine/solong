/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:23:32 by mochenna          #+#    #+#             */
/*   Updated: 2024/03/27 23:21:40 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void convert_img(t_solong *img)
{
    int s;
    int s1;
    int f;

    s = ALL;
    s1 = 45;
    f = 100;
    img->img_ptr = mlx_xpm_file_to_image(img->mlx,"img/walls1.xpm",&s,&s);
    img->img_ptr1 = mlx_xpm_file_to_image(img->mlx,"img/player.xpm",&s,&s);
    img->img_ptr2 = mlx_xpm_file_to_image(img->mlx,"img/collectible.xpm",&s1,&s1);
    img->img_ptr3 = mlx_xpm_file_to_image(img->mlx,"img/exit_close.xpm",&f,&f);
    img->img_ptr4 = mlx_xpm_file_to_image(img->mlx,"img/exit_close.xpm",&f,&f);
}
void put_image(t_solong *so_long)
{
    int i;
    int j;

    convert_img(so_long);
    i = 0;
    while(i < so_long->y)
    {
        j = 0;
        while(j < so_long->x)
        {
            if(so_long->map[i][j] == '1')
                mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,so_long->img_ptr, j * ALL, i * ALL);
            else if(so_long->map[i][j] == 'E')
                mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,so_long->img_ptr3, j * ALL, i * ALL);
            else if(so_long->map[i][j] == 'P')
                mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,so_long->img_ptr1, j * ALL, i * ALL);
            else if(so_long->map[i][j] == 'C')
                mlx_put_image_to_window(so_long->mlx, so_long->mlx_win,so_long->img_ptr2, j * ALL, i * ALL);
            j++;
        }
        i++;
    }
}
int	key_hook(int keycode, t_solong *v)
{
    if (keycode == 53)
        printf("gome is over\n");
    else if(keycode == 0 || keycode == 123)
        printf("go left\n");
    else if(keycode == 2 || keycode == 124)
        move_to_right(v);
    else if(keycode == 13 || keycode == 126)
        printf("go up\n");
    else if(keycode == 1 || keycode == 125)
        printf("go down\n");
	return (0);
}
void event_key(t_solong *solong)
{
    get_positon(solong->map,&solong->event.y,&solong->event.x);
    printf("x == %d\n",solong->event.x);
    printf("x == %d\n",solong->event.y);
    solong->event.move = 0;
    mlx_key_hook(solong->mlx_win, key_hook, solong);
}