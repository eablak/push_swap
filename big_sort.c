/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:53:23 by eablak            #+#    #+#             */
/*   Updated: 2022/12/20 17:02:54 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*cr_copy_arr(t_struct **a, int size)
{
	int			i;
	int			*arr;
	t_struct	*begin;

	i = 0;
	begin = (*a);
	arr = malloc(sizeof(int) * size);
	while (i < size)
	{
		arr[i] = begin->data;
		begin = begin->next;
		i++;
	}
	bubble_sort(arr, size);
	return (arr);
}

int	is_descending(t_struct **a, int size)
{
	int			data;
	int			flag;
	t_struct	*keep_a;
	t_struct	*begin;
	t_struct	*second_a;

	begin = (*a);
	keep_a = begin;
	second_a = keep_a;
	flag = 0;
	while (size > 0)
	{
		begin = second_a;
		data = begin->data;
		while (begin)
		{
			if (data < begin->data)
				flag = 1;
			begin = begin->next;
		}
		size--;
		second_a = second_a->next;
	}
	begin = keep_a;
	return (flag);
}

void	ft_forall(t_struct **a, t_struct *b, int size)
{
	t_struct	*begin;
	t_struct	*keep_begin;
	t_struct2	sorted;
	t_holder	*holder;
	int			*arr;

	begin = (*a);
	keep_begin = begin;
	holder = malloc(sizeof(t_holder));
	holder->a = begin;
	holder->b = b;
	if (is_descending(&begin, size) != 1)
		ra(&begin);
	holder->a = begin;
	sorted = find_sort(&begin);
	arr = cr_copy_arr(&begin, size);
	sorted_stay_a(holder, sorted, size);
	find_min_step(holder, arr);
	free(arr);
}
