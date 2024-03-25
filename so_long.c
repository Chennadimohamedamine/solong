/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:55:52 by mochenna          #+#    #+#             */
/*   Updated: 2024/03/25 15:41:13 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void so_long(char *av)
{
    t_solong *so_long;

    so_long = malloc(sizeof(so_long));
    so_long->map = lines(av,&so_long->y);
    so_long->x = ft_strlen(so_long->map[0]);
    so_long->mlx = mlx_init();
    so_long->x *= X;
    so_long->y *= Y;
    so_long->mlx_win = mlx_new_window(so_long->mlx,so_long->x,so_long->y,"so_long");
   mlx_loop(so_long->mlx_win);
}
int main(int ac, char **av)
{
    if (ac != 2 || av[1] == 0)
    {
        write(2, "Error\n",6);
        return (1);
    }
    so_long(av[1]);
    // char **str = lines(av[1],&ac);
    return (0);
}

/*
mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
*/