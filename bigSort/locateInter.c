/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:12:03 by eablak            #+#    #+#             */
/*   Updated: 2022/12/26 11:47:57 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	locateInter_utils(t_holder *holder, int b_index, t_struct *keep_a, int *arr)
{
	int	count;
	int	out;

	count = 0;
	out = 0;
	while (b_index < (holder->size_a + holder->size_b))
	{
		holder->a = keep_a;
		count = 0;
		while (holder->a)
		{
			if (arr[b_index] == holder->a->data)
			{
				out = 1;
				break ;
			}
			holder->a = holder->a->next;
			count++;
		}
		if (out == 1)
			break ;
		b_index++;
	}
	return (count);
}

void	locateInter(t_holder *holder, int *arr)
{
	int			data;
	int			b_index;
	t_struct	*keep_a;
	int			count;

	data = holder->b->data;
	b_index = 0;
	keep_a = holder->a;
	while (b_index < holder->size_a + holder->size_b)
	{
		if (arr[b_index] == data)
			break ;
		b_index++;
	}
	b_index++;
	count = locateInter_utils(holder, b_index, keep_a, arr);
	holder->a = keep_a;
	ft_finish(holder, count);
}

void	array_control(char *all_array)
{
	if (all_array == NULL)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
