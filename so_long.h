/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:55:55 by mochenna          #+#    #+#             */
/*   Updated: 2024/03/17 18:06:17 by mochenna         ###   ########.fr       */
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
# endif

char	*ft_strjoin(char *s1, char *s2);
char *readall(char *s, int fd);
char	*ft_strdup(char *s1);
char	**splitnewline(char *s, int *len, char l);
size_t	ft_strlen(char *str);
// ! parsing
void checkall(char *s1, char **s,int i);

// * all about free memory
void freememory(int c, char **v);
void failer_malloc(char **s,char *s2 ,char *s1,int i);
void error_handling(char *s, char **s1, int i);

// ! temp
void print(char **s);

#endif