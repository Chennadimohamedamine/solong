/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:55:52 by mochenna          #+#    #+#             */
/*   Updated: 2024/03/26 18:31:30 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void convert(t_solong *img)
{
    int s;
    int s1;

    s = ALL;
    s1 = 45;
    img->img_ptr = mlx_xpm_file_to_image(img->mlx,"img/walls1.xpm",&s,&s);
    img->img_ptr1 = mlx_xpm_file_to_image(img->mlx,"img/player.xpm",&s,&s);
    img->img_ptr2 = mlx_xpm_file_to_image(img->mlx,"img/collectible.xpm",&s1,&s1);
    img->img_ptr3 = mlx_xpm_file_to_image(img->mlx,"img/exit1.xpm",&s,&s);
    // convert->con->img_ptr1 = mlx_xpm_file_to_image(convert->mlx,"img/img2.xpm",&s,&s);
    // convert->con->img_ptr2 = mlx_xpm_file_to_image(convert->mlx,"img/img3.xpm",&s,&s);
    // convert->con->img_ptr3 = mlx_xpm_file_to_image(convert->mlx,"img/img1.xpm",&s,&s);
    // convert->con->img_ptr4 = mlx_xpm_file_to_image(convert->mlx,"img/img4.xpm",&s,&s);
    // convert->con->img_ptr = mlx_xpm_file_to_image(so_long->mlx,"img/img5.xpm",40,40);
}
void put_image(t_solong *so_long)
{
    int i;
    int j;

    convert(so_long);
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
void so_long(char *av)
{
    t_solong so_long;
    
    so_long.map = lines(av,&so_long.y);
    so_long.x = ft_strlen(so_long.map[0]);
    so_long.mlx = mlx_init();
    so_long.mlx_win = mlx_new_window(so_long.mlx,so_long.x * ALL,so_long.y * ALL,"so_long");
    put_image(&so_long);
    mlx_loop(so_long.mlx);
    // exit(0);
}
int main(int ac, char **av)
{
    if (ac != 2 || av[1] == 0)
    {
        write(2, "Error\n",6);
        return (1);
    }
    so_long(av[1]);
    return (0);
}

/*
mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
*/