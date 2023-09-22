/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 13:31:28 by eablak            #+#    #+#             */
/*   Updated: 2022/12/21 19:05:23 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	binary_sorting(t_struct **a)
{
	t_struct	*begin;

	begin = *a;
	if (begin->data > begin->next->data)
		ra(a);
	ft_free(a);
}

void	triple_sorting(t_struct **a, int flag)
{
	t_struct	*begin;

	begin = *a;
	if (begin->data < begin->next->data && begin->data < begin->next->next->data
		&& begin->next->data > begin->next->next->data)
	{
		rra(&begin);
		sa(&begin);
	}
	else if (begin->data > begin->next->data
		&& begin->data > begin->next->next->data
		&& begin->next->data < begin->next->next->data)
		ra(&begin);
	else if (begin->data < begin->next->data
		&& begin->data > begin->next->next->data
		&& begin->next->data > begin->next->next->data)
		rra(&begin);
	(*a) = begin;
	triple_utils(a);
	if (flag == 1)
		ft_free(a);
}

void	triple_utils(t_struct **a)
{
	t_struct	*begin;

	begin = *a;
	if (begin->data > begin->next->data && begin->data < begin->next->next->data
		&& begin->next->data < begin->next->next->data)
		sa(&begin);
	else if (begin->next->next->data < begin->data
		&& begin->next->data < begin->data
		&& begin->next->next->data < begin->next->data)
	{
		ra(&begin);
		sa(&begin);
	}
	(*a) = begin;
}

void	process_by_size(int size, t_struct **my_struct)
{
	t_struct	*b;

	b = malloc(sizeof(t_struct));
	if (size == 1)
		exit(1);
	else if (size == 2)
		binary_sorting(my_struct);
	else if (size == 3)
		triple_sorting(my_struct, 1);
	else if (size == 4 || size == 5)
		quartet_quintette(my_struct, b, size);
	else if (size > 5)
		big_sort(my_struct, b, size);
	free(b);
}
