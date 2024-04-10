/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:26:46 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/10 22:30:04 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void  game_over(t_solong *solong, char *str)
{
    int i;

    i = 0;
    while (str[i])
        write(1,&str[i++],1);
    mlx_destroy_image(solong->mlx, solong->player[0]);
    mlx_destroy_image(solong->mlx, solong->player[1]);
    mlx_destroy_image(solong->mlx, solong->player[2]);
    mlx_destroy_image(solong->mlx, solong->player[3]);
    mlx_destroy_image(solong->mlx, solong->walls);
    mlx_destroy_image(solong->mlx, solong->close);
    mlx_destroy_image(solong->mlx, solong->open);
    mlx_destroy_window(solong->mlx, solong->mlx_win);
    freememory(solong->y,solong->map);
    exit(0);
}