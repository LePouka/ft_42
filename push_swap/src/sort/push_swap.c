/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:03:00 by rtissera          #+#    #+#             */
/*   Updated: 2023/04/24 18:54:07 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	littlesort(t_list **a)
{
	t_list	*n;

	n = (*a)->next;
	if ((*a)->content == 1 && n->content == 0)
		sa(a);
	else if ((*a)->content == 1 && n->content == 3)
		rra(a);
	else if ((*a)->content == 3 && n->content == 0)
		ra(a);
	else if ((*a)->content == 3 && n->content == 1)
	{
		sa(a);
		rra(a);
	}
	else
	{
		sa(a);
		ra(a);
	}
}

void	littlesort2(t_list **a, t_list **b, t_list *head)
{
	while (*a)
	{
		if ((*a)->content > 3)
			pb(a, b);
		*a = (*a)->next;
	}
	*a = head;
	littlesort(a);
	if (*b)
	{
		if ((*b)->content == 4)
		{
			pa(a, b);
			ra(a);
			pa(a, b);
			ra(a);
		}
		else
		{
			pa(a, b);
			pa(a, b);
			ra(a);
			ra(a);
		}
	}
}

void	push_last_bit_one(t_list **a, t_list **b, int bit_max)
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
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

void	big_sort(t_list *stocka, t_list *stockb)
{
	int	max_num;
	int	bit_max;

	max_num = ft_max(stocka);
	bit_max = 0;
	while (max_num >> bit_max)
	{
		push_last_bit_one(&stocka, &stockb, bit_max);
		while (ft_lstsize(stockb) > 0)
			pa(&stocka, &stockb);
		bit_max++;
	}
	lst_clean(&stocka);
	lst_clean(&stockb);
}

void	push_swap(int argc, t_list *stocka)
{
	t_list	*stockb;

	stockb = NULL;
	if (argc == 4)
		littlesort(&stocka);
	else if (argc == 6)
		littlesort2(&stocka, &stockb, NULL);
	else
		big_sort(stocka, stockb);
}
