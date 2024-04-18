/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 22:05:04 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/18 02:32:03 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 10
#  define ALL 60
# endif

struct s_enmy
{
	int	p_x;
	int	p_y;
	int	dir;
};

struct s_game
{
	int		x;
	int		y;
	int		move;
	char	*copy_map;
	char	*move_str;
	int		collectible;
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
	void			*enms[2];
	void			*player[4];
	void			*collect;
	void			*close;
	void			*open;
	void			*bg;
	char			direction;
	struct s_game	event;
	struct s_enmy	enm;
}	t_solong;

void	freememory(int c, char **v);
void	failer_malloc(char **s, char *s2, char *s1, int i);
void	error_handling(char *s, char **s1, int i);
char	**lines(t_solong*solong, char *av, int *y);
char	*ft_strjoin(char *s1, char *s2);
char	*readall(int fd);
char	*ft_strdup(char *s1);
char	**splitnewline(char *s, int *len, char l);
int		ft_strlen(char *str);
void	checkall(char *s1, char **s, int i);
int		check_ens(char *s, char *s1);
void	invalid_game(char *s1);
void	check_validgame(t_solong *solong);
void	print_move(t_solong *solong);
char	*ft_itoa(int n);
void	convert_image(t_solong *img);
void	put_img(t_solong *so_long);
int		key_hooks(int keycode, t_solong *v);
void	exit_status(t_solong *so_long, int i, int j);
void	move_enmy(t_solong *solong, int i, int j);
void	player_direction(t_solong *solong, int i, int j);
void	make_enmy(t_solong *solong);
int		loop_hook(t_solong *solong);
void	move_to_left(t_solong *solong);
void	move_to_up(t_solong *solong);
void	move_to_right(t_solong *solong);
void	move_to_down(t_solong *solong);
void	get_positon_exit(char **s, int *x, int *y);
void	get_positon(char **s, int *x, int *y);
int		all_collect(char **map);
void	game_over(t_solong *solong, char *str);
void	animation(t_solong *solong);
int		ft_close_(t_solong *solong);
#endif