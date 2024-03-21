/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:55:52 by mochenna          #+#    #+#             */
/*   Updated: 2024/03/21 17:17:58 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void so_long(char *av)
{
   char **map;
   int h[2];
   void *mlx;
   void *mlx_win;

   map = lines(av,&h[0]);
   mlx = mlx_init();
   h[1] = ft_strlen(map[0]) * 25;
   h[0] *= 80;
   mlx_win = mlx_new_window(mlx,h[1],h[0],"so_long");
   mlx_loop(mlx);
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