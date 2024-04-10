/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:04:37 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/08 15:12:40 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void so_long_bonus(char *av)
{
    t_solong so_long;
    
    so_long.map = lines(av,&so_long.y);
    so_long.x = ft_strlen(so_long.map[0]);
    so_long.mlx = mlx_init();
    so_long.mlx_win = mlx_new_window(so_long.mlx,so_long.x * ALL,so_long.y * ALL,"<><> so_long <><>");
    drow_game(&so_long);
    mlx_loop(so_long.mlx);
}
int main(int ac, char **av)
{
    if (ac != 2 || av[1] == 0)
    {
        write(2, "Error\n",6);
        return (1);
    }
    so_long_bonus(av[1]);
    return (0);
}