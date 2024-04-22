/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:55:55 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/23 00:43:07 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
#  define ALL 60
# endif

struct	s_game
{
	int	x;
	int	y;
	int	move;
	int	collectible;
};

typedef struct so_long
{
	int				x;
	int				y;
	int				x_e;
	int				y_e;
	char			**map;
	void			*mlx;
	void			*mlx_win;
	void			*img;
	void			*walls;
	void			*player[4];
	void			*collect;
	void			*close;
	void			*open;
	void			*bg;
	char			direction;
	struct s_game	event;
}	t_solong;

char	**lines(char *av, int *y);
void	put_image(t_solong *so_long);
void	convert_img(t_solong *img);
void	get_positon(char **s, int *x, int *y);
void	print_move(int i);
int		all_collect(char **map);
void	get_positon_exit(char **s, int *x, int *y);
int		ft_close(t_solong *solong);
void	game_over(t_solong *solong, char *str);
void	game(t_solong *solong);
void	move_to_right(t_solong *solong);
void	move_to_left(t_solong *solong);
void	move_to_down(t_solong *solong);
void	move_to_up(t_solong *solong);
void	player_direction(t_solong *solong, int i, int j);
char	*ft_strjoin(char *s1, char *s2);
char	*readall(int fd);
char	*ft_strdup(char *s1);
char	**splitnewline(char *s, int *len, char l);
int		ft_strlen(char *str);
void	checkall(char *s1, char **s, int i);
int		check_ens(char *s, char *s1);
void	invalid_game(char *s1);
void	freememory(int c, char **v);
void	failer_malloc(char **s, char *s2, char *s1, int i);
void	error_handling(char *s, char **s1, int i);
void	put_exit(t_solong *so_long, int i, int j);
int		key_hook(int keycode, t_solong *v);
void	put_coll_and_bg(t_solong *so_long, int i, int j);
#endif
