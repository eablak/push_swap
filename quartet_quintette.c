/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_part2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:51:06 by eablak            #+#    #+#             */
/*   Updated: 2022/12/21 19:06:03 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_b(t_holder *holder, int i)
{
	if (i == 1 && (holder->size_a == 4 || holder->size_a == 5))
		ra(&(holder->a));
	else if (i == 2 && holder->size_a == 4)
	{
		rra(&(holder->a));
		rra(&(holder->a));
	}
	else if (i == 2 && holder->size_a == 5)
	{
		ra(&(holder->a));
		ra(&(holder->a));
	}
	else if ((i == 3 && holder->size_a == 4) || (holder->size_a == 5 && i == 4))
		rra(&(holder->a));
	else if (i == 3 && holder->size_a == 5)
	{
		rra(&(holder->a));
		rra(&(holder->a));
	}
	pb(holder);
}

void	find_min_data(t_holder *holder)
{
	t_struct	*begin;
	int			min;
	int			i;

	begin = holder->a;
	min = holder->a->data;
	i = 0;
	while (holder->a)
	{
		if (holder->a->data < min)
			min = holder->a->data;
		holder->a = holder->a->next;
	}
	holder->a = begin;
	while (1)
	{
		if (begin->data == min)
			break ;
		begin = begin->next;
		i++;
	}
	send_b(holder, i);
}

void	quartet_quintette(t_struct **a, t_struct *b, int size)
{
	t_holder	*holder;
	t_struct	*keep_a;
	int			i;

	i = 0;
	holder = malloc(sizeof(t_holder));
	holder->a = (*a);
	keep_a = holder->a;
	holder->b = b;
	holder->size_a = size;
	while (holder->size_a > 3)
	{
		find_min_data(holder);
		i++;
	}
	triple_sorting(&(holder->a), 0);
	while (i > 0)
	{
		pa(holder);
		i--;
	}
	ft_free(&(holder->a));
	free(holder);
}
