/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_onehalf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:31:25 by eablak            #+#    #+#             */
/*   Updated: 2022/12/20 16:19:36 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	find_sorted_max(t_strct_bigsort *big_strct)
{
	big_strct->temp = big_strct->begin;
	while (big_strct->begin->next != NULL
		&& big_strct->begin->data < big_strct->begin->next->data)
	{
		big_strct->len++;
		if (big_strct->begin->next != NULL)
			big_strct->begin = big_strct->begin->next;
	}
	big_strct->temp2 = big_strct->begin;
	if (big_strct->len > big_strct->real_len)
	{
		big_strct->real_len = big_strct->len;
		big_strct->start = big_strct->temp;
		big_strct->end = big_strct->temp2;
	}
	big_strct->len = 0;
}

sorted_struct	find_sorted(t_struct **a)
{
	t_strct_bigsort	*big_strct;
	sorted_struct		sortedd;

	big_strct = malloc(sizeof(t_strct_bigsort));
	big_strct->begin = (*a);
	big_strct->len = 0;
	big_strct->real_len = 0;
	while (big_strct->begin->next)
	{
		if (big_strct->begin->data < big_strct->begin->next->data)
			find_sorted_max(big_strct);
		else
			big_strct->begin = big_strct->begin->next;
	}
	big_strct->sorted.first = big_strct->start->data;
	big_strct->sorted.len = big_strct->real_len + 1;
	sortedd = big_strct->sorted;
	free(big_strct);
	return (sortedd);
}

void	end_valueB(t_struct *b, int len_b)
{
	t_struct	*keep_b;
	int			i;

	i = 1;
	keep_b = b;
	while (i < len_b)
	{
		b = b->next;
		i++;
	}
	b->next = NULL;
	b = keep_b;
}

void	sorted_stayA(t_holder *holder, int i)
{
	while (i > 0)
	{
		ra(&(holder->a));
		i--;
	}
}

void	placing_values(t_holder *holder, sorted_struct sorted, int size)
{
	int			i;
	int			len_b;
	t_struct	*keep_b;

	i = sorted.len;
	holder->size_a = size;
	holder->size_b = 0;
	len_b = 0;
	keep_b = holder->b;
	while (size - sorted.len + 1 > 0)
	{
		if (holder->a->data == sorted.first)
			sorted_stayA(holder, i);
		else
		{
			pb(holder);
			len_b++;
		}
		size--;
	}
	end_valueB(holder->b, len_b);
}
