/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:05:04 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/10 22:16:13 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
#define SO_LONG_BONUS_H

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <libc.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 10
#  define ALL 60
# endif

struct enamey
{
    int x;
    int y;
    int direction;
};

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
    int x_e;
    int y_e;
    char **map;
    void *mlx;
    void *mlx_win;
	void	*img;
    void *walls;   
    void *player[4];  
    void *enmy_[2]; 
    void *collect;   
    void *close;   
    void *open;
    void *bg;
    char direction;
    struct game event;
    struct enamey enmy;
} t_solong;


char	**lines(char *av, int *y);
char	*ft_strjoin(char *s1, char *s2);
char *readall(int fd);
char	*ft_strdup(char *s1);
char	**splitnewline(char *s, int *len, char l);
int	ft_strlen(char *str);
void checkall(char *s1, char **s,int i);
int check_ens(char *s,char *s1);
void invalid_game(char *s1);
void freememory(int c, char **v);
void failer_malloc(char **s,char *s2 ,char *s1,int i);
void error_handling(char *s, char **s1, int i);

// -------------------
int all_collect(char **map);
void put_img(t_solong *solong);
void convert_img_(t_solong *img);
void player_direction(t_solong *solong, int i, int j);
int	key_hook(int key,t_solong *v);
int	loop_hook(t_solong *v);

void move_to_right(t_solong *solong);
void move_to_left(t_solong *solong);
void move_to_down(t_solong *solong);
void move_to_up(t_solong *solong);
void player_direction(t_solong *solong, int i, int j);
int ft_close(t_solong *solong);

// khass b img
void drow_game(t_solong *solong);
void get_positon_exit(char **s, int *x, int *y);
void get_positon(char **s, int *x, int *y);
int check_path(char **s);






void print(char **s);
#endif