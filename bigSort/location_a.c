/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_twohalf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:49:21 by eablak            #+#    #+#             */
/*   Updated: 2022/12/20 16:34:23 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_in_arr(int *arr, int data, t_holder *holder)
{
	int	i;
	int	size;

	i = 0;
	size = holder->size_a + holder->size_b;
	while (i < size)
	{
		if (arr[i] == data)
			break ;
		i++;
	}
	return (i);
}

int	check_min(t_holder *holder)
{
	t_struct	*keep_a;
	int			numberb;
	int			numbera;

	numberb = holder->b->data;
	numbera = holder->a->data;
	keep_a = holder->a;
	while (holder->a)
	{
		if (holder->a->data < numbera)
			numbera = holder->a->data;
		holder->a = holder->a->next;
	}
	holder->a = keep_a;
	if (numberb < numbera)
		return (1);
	return (0);
}

int	check_max(t_holder *holder)
{
	t_struct	*keep_a;
	int			numberb;
	int			numbera;

	numberb = holder->b->data;
	numbera = holder->a->data;
	keep_a = holder->a;
	while (holder->a)
	{
		if (holder->a->data > numbera)
			numbera = holder->a->data;
		holder->a = holder->a->next;
	}
	holder->a = keep_a;
	if (numberb > numbera)
		return (1);
	return (0);
}

int	up_min_a(t_holder *holder)
{
	t_struct	*keep_a;
	int			number;
	int			i;
	int			count;

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
	if (count > holder->size_a / 2)
		count = (holder->size_a) - count;
	return (count);
}

int	location_a(t_holder *holder, int *arr)
{
	int			data;
	t_struct	*keep_a;
	int			i;

	data = holder->b->data;
	i = 0;
	keep_a = holder->a;
	if (check_min(holder) == 1)
		i = up_min_a(holder);
	else if (check_max(holder) == 1)
		i = up_min_a(holder);
	else
		i = correct_count(holder, arr, data);
	holder->a = keep_a;
	if (i > holder->size_a / 2)
		i = holder->size_a - i;
	return (i);
}
