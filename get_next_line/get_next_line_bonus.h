/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:19:29 by rtissera          #+#    #+#             */
/*   Updated: 2023/02/22 12:49:51 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 420
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			buf[BUFFER_SIZE + 1];
	struct s_list	*next;
}	t_list;

int		ft_lstsize(t_list *lst);
int		linelen(t_list **lst, int boool);
char	*get_next_line(int fd);
char	*put_in_line(t_list **lst, int i, int j);
void	*read_error(t_list **lst);
void	clear_old_line(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(char *buf);
t_list	*ft_lstlast(t_list *lst);
t_list	*read_line(t_list **lst, int fd);

#endif
