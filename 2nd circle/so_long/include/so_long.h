/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:20:04 by rtissera          #+#    #+#             */
/*   Updated: 2023/09/06 17:20:22 by rtissera         ###   ########.fr       */
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
typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}	t_vars;

typedef struct s_sprite {
	char	*collectible;
	char	*character;
	char	*floor;
	char	*wall;
	char	*exit;
}	t_sprite;

typedef struct s_map {
	char			**map;
	unsigned int	x_max;
	unsigned int	y_max;
}	t_map;

/************************************************/
/*   FUNCTIONS                                  */
/************************************************/
int			close_window(t_vars *vars);
int			ft_clear_vars(t_vars *vars);
int			ft_handle_key(int key, t_vars *vars);
void		error(char *str);
void		clear(char **tab);
void		check_map(t_map map);
void		print_sprite(t_vars vars, char *sprite, int x, int y);
void		print_map(t_vars vars, t_sprite sprite, char *map_path);
t_map		read_map(int map_fd);
size_t		malloc_strlcpy(char *dst, const char *src, size_t size);
t_sprite	init_sprite(void);

#endif
