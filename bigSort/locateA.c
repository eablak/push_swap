/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_part4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:03:05 by eablak            #+#    #+#             */
/*   Updated: 2022/12/20 16:59:19 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_make_a(t_holder *holder, int count)
{
	int	i;

	i = 0;
	if (count <= holder->size_a / 2)
	{
		while (count > i)
		{
			ra(&(holder->a));
			i++;
		}
	}
	else
	{
		count = holder->size_a - count;
		while (count > i)
		{
			rra(&(holder->a));
			i++;
		}
	}
}

void	moveUpA(t_holder *holder)
{
	t_struct	*keep_a;
	int			number;
	int			i;
	int			count;

	keep_a = holder->a;
	keep_a = holder->a;
	number = holder->a->data;
	i = 0;
	count = 0;
	while (holder->a)
	{
		if (holder->a->data < number)
		{
			number = holder->a->data;
			count = i;
		}
		i++;
		holder->a = holder->a->next;
	}
	holder->a = keep_a;
	ft_make_a(holder, count);
}

void	ft_finish(t_holder *holder, int count)
{
	int	i;

	i = 0;
	if (count <= (holder->size_a / 2))
	{
		while (i < count)
		{
			ra(&(holder->a));
			i++;
		}
	}
	else
	{
		count = holder->size_a - count;
		while (i < count)
		{
			rra(&(holder->a));
			i++;
		}
	}
}

void	locateA(t_holder *holder, int *arr)
{
	if (check_min(holder))
		moveUpA(holder);
	else if (check_max(holder))
		moveUpA(holder);
	else
		locateInter(holder, arr);
}
