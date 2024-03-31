/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:55:55 by mochenna          #+#    #+#             */
/*   Updated: 2024/03/31 22:39:21 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 10
#  define ALL 60
# endif


struct game
{  
    int x;
    int y;
    int move;
    int collectible;
};

typedef struct so_long
{
    int x;
    int y;
    // int move;
    char **map;
    void *mlx;
    void *mlx_win;
	void	*img;
    void *img_ptr;   
    void *img_ptr1;   
    void *img_ptr2;   
    void *img_ptr3;   
    void *img_ptr4;
    void *img_ptr5;
    struct game event;
} t_solong;

// *program
char **lines(char *av,int *y);
void put_image(t_solong *so_long);
void convert_img(t_solong *img);
void get_positon(char **s, int *x, int *y);
void swap_value(char *s1,char *s2);
// move and key and event
void print_move(int i);
int all_collect(char **map);


void event_key(t_solong *solong);
void move_to_right(t_solong *solong);
void move_to_left(t_solong *solong);
void move_to_down(t_solong *solong);
void move_to_up(t_solong *solong);


// * file use them to exuct
char	*ft_strjoin(char *s1, char *s2);
char *readall(int fd);
char	*ft_strdup(char *s1);
char	**splitnewline(char *s, int *len, char l);
int	ft_strlen(char *str);

// ! parsing
void checkall(char *s1, char **s,int i);
int check_ens(char *s,char *s1);
void invalid_game(char *s1);

// * all about free memory
void freememory(int c, char **v);
void failer_malloc(char **s,char *s2 ,char *s1,int i);
void error_handling(char *s, char **s1, int i);

// ! temp
void print(char **s);

#endif