/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:32:37 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/17 19:19:15 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_double(char *s)
{
	int	i;
	int	g[4];

	i = 0;
	while (i < 4)
		g[i++] = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == 'C')
			g[0]++;
		else if (s[i] == 'P' || s[i] == 'E')
			g[1]++;
		i++;
	}
	if (g[0] == 0 || g[1] != 2)
		return (1);
	return (0);
}

void	check_gui(char *s1, char **s, int i)
{
	int	j;
	int	len;
	int	c;

	j = 0;
	len = ft_strlen(s[0]);
	while (s[j])
	{
		if (len != ft_strlen(s[j]) || (s[j][0] != '1' || s[j][len - 1] != '1'))
			error_handling(s1, s, i);
		if (j == 0 || j == i - 1)
		{
			c = 0;
			while (s[j][c])
			{
				if (s[j][c++] != '1')
					error_handling(s1, s, i);
			}
		}
		j++;
	}
	if (check_double(s1))
		error_handling(s1, s, i);
}

void	checkall(char *s1, char **s, int i)
{
	int	j;
	if (i < 3 || s1[0] == '\n')
		error_handling(s1, s, i);
	j = 0;
	while (s1[j])
	{
		if (s1[j] == '\n' && (s1[j + 1] == '\n' || s1[j + 1] == 0))
			error_handling(s1, s, i);
		if (s1[j] != 'P' && s1[j] != '0' && s1[j] != '1'  && s1[j] != 'C' && s1[j] != 'E' && s1[j] != '\n')
			error_handling(s1, s, i);
		j++;
	}
	check_gui(s1, s, i);
}

char	**lines(t_solong *solong, char *av, int *y)
{
	char	**lines;
	int		i;

	if (check_ens(av + (ft_strlen(av) - 4), ".ber") != 0 || ft_strlen(av) < 4)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i = open(av, O_RDONLY);
	if (i < 0)
	{
		write(2,"<< can not open this file >>\n",29);
		exit(1);
	}
	solong->event.copy_map= readall(i);
	close(i);
	lines = splitnewline(solong->event.copy_map, &i, '\n');
	checkall(solong->event.copy_map, lines, i);
	invalid_game(solong->event.copy_map);
	*y = i;
	return (lines);
}