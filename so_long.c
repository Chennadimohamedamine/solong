/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:55:52 by mochenna          #+#    #+#             */
/*   Updated: 2024/03/20 22:40:44 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void so_long(char *av)
{
   char **map;
   
   map = lines(av);
//    print(map);
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