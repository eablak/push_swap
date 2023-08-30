/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_part2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:44:07 by eablak            #+#    #+#             */
/*   Updated: 2022/12/20 16:43:49 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	correct_utils(t_holder *holder, int *arr, int index, t_struct *keep_a)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (index <= holder->size_a + holder->size_b)
	{
		holder->a = keep_a;
		i = 0;
		while (holder->a)
		{
			if (holder->a->data == arr[index])
			{
				flag = 1;
				break ;
			}
			else
				holder->a = holder->a->next;
			i++;
		}
		if (flag == 1)
			break ;
		index++;
	}
	return (i);
}

int	correct_count(t_holder *holder, int *arr, int data)
{
	t_struct	*keep_a;
	int			index;
	int			i;

	i = 0;
	keep_a = holder->a;
	index = 0;
	index = find_in_arr(arr, data, holder) + 1;
	i = correct_utils(holder, arr, index, keep_a);
	holder->a = keep_a;
	return (i);
}

int	up_b(t_holder *holder, t_struct *use_b, int data)
{
	int			i;
	int			size;
	t_struct	*keep_b;
	int			flag;

	i = 0;
	size = 0;
	keep_b = holder->b;
	flag = 0;
	while (use_b)
	{
		if (use_b->data == data && size <= holder->size_b / 2)
			break ;
		else if (use_b->data == data && size > holder->size_b / 2)
		{
			size = holder->size_b - size;
			break ;
		}
		use_b = use_b->next;
		size++;
	}
	holder->b = keep_b;
	if (flag)
		return (size);
	return (size);
}

void	find_min_step(t_holder *holder, int *arr, t_struct *second_b)
{
	int	min_len;
	int	step_len;
	int	data;

	min_len = 2147483647;
	while (holder->b)
	{
		step_len = 0;
		step_len += up_b(holder, second_b, holder->b->data);
		step_len += location_a(holder, arr);
		if (step_len <= min_len)
		{
			min_len = step_len;
			data = holder->b->data;
		}
		holder->b = holder->b->next;
	}
	holder->b = second_b;
	ft_run_as(data, holder);
	locate_a(holder, arr);
	pa(holder);
}

void	replacement(t_holder *holder, int *arr)
{
	t_struct	*keep_b;
	t_struct	*second_b;

	keep_b = holder->b;
	while (holder->size_b)
	{
		second_b = holder->b;
		find_min_step(holder, arr, second_b);
	}
	make_up_a(holder);
	ft_free(&(holder->a));
	free(holder);
}
