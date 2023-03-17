/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:03:00 by rtissera          #+#    #+#             */
/*   Updated: 2023/03/17 15:54:07 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_last_bit_one(t_list **a, t_list **b, int bit_max, bool log)
{
	int	i;
	int	tmp;
	int	size;

	i = 0;
	size = ft_lstsize(*a);
	while (i < size)
	{
		tmp = (*a)->content;
		if (((tmp >> bit_max) & 1) == 0)
			pb(a, b, log);
		else
			ra(a, log);
		i++;
	}
}

void	big_sort(t_list *stocka, t_list *stockb, bool log)
{
	int	max_num;
	int	bit_max;

	max_num = ft_max(stocka);
	bit_max = 0;
	while (max_num >> bit_max)
	{
		push_last_bit_one(&stocka, &stockb, bit_max, log);
		while (ft_lstsize(stockb) > 0)
			pa(&stocka, &stockb, log);
		bit_max++;
	}
	lst_clean(&stocka);
	lst_clean(&stockb);
}

void	push_swap(t_list *stocka)
{
	t_list	*stockb;

	stockb = NULL;
	big_sort(stocka, stockb, true);
}