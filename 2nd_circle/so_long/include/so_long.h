/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:20:04 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/18 15:56:35 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/************************************************/
/*   WRAPPER                                    */
/************************************************/
#ifndef SO_LONG_H
# define SO_LONG_H

/************************************************/
/*   INCLUDES                                   */
/************************************************/
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/include/libft.h"

/************************************************/
/*   STRUCTURES                                 */
/************************************************/
typedef struct s_sprite {
	char	*collectible;
	char	*character;
	char	*floor;
	char	*wall;
	char	*exit;
}	t_sprite;

typedef struct s_image {
	void	*col;
	void	*cha;
	void	*flo;
	void	*wal;
	void	*exi;
}	t_image;

typedef struct s_map {
	char			**map;
	unsigned int	x;
	unsigned int	y;
	unsigned int	p_x;
	unsigned int	p_y;
	unsigned int	cp;
	unsigned int	ce;
	unsigned int	cc;
}	t_map;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_map		m;
	t_image		img;
}	t_vars;

/************************************************/
/*   FUNCTIONS                                  */
/************************************************/
int			close_window(t_vars *vars);
int			ft_clear_vars(t_vars *vars);
int			ft_handle_key(int key, t_vars *vars);
void		error(char *str);
void		clear(char **tab);
void		check_map(t_map *map);
void		findstart(t_map *map);
void		clearror(char **tab, char *str);
void		move_up(t_vars *vrs, t_map *map);
void		move_down(t_vars *vrs, t_map *map);
void		move_left(t_vars *vrs, t_map *map);
void		move_right(t_vars *vrs, t_map *map);
void		print_map(t_vars *vars, t_map map);
t_map		mapcpy(t_map *map);
t_map		read_map(int map_fd);
t_map		drop(t_map c_map, unsigned int x, unsigned int y);
t_map		findaway(t_map map, unsigned int x, unsigned int y);
t_image		init_image(t_sprite sprite, t_vars vars);
t_sprite	init_sprite(void);

#endif
