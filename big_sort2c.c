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

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	find_sort_2(t_strct_bigsort *st_b_s)
{
	st_b_s->temp = st_b_s->begin;
	while (st_b_s->begin->next != NULL
		&& st_b_s->begin->data < st_b_s->begin->next->data)
	{
		st_b_s->len++;
		if (st_b_s->begin->next != NULL)
			st_b_s->begin = st_b_s->begin->next;
	}
	st_b_s->temp2 = st_b_s->begin;
	if (st_b_s->len > st_b_s->real_len)
	{
		st_b_s->real_len = st_b_s->len;
		st_b_s->start = st_b_s->temp;
		st_b_s->end = st_b_s->temp2;
	}
	st_b_s->len = 0;
}

t_struct2	find_sort(t_struct **a)
{
	t_strct_bigsort	*st_b_s;
	t_struct2		sortedd;

	st_b_s = malloc(sizeof(t_strct_bigsort));
	st_b_s->begin = (*a);
	st_b_s->len = 0;
	st_b_s->real_len = 0;
	while (st_b_s->begin->next)
	{
		if (st_b_s->begin->data < st_b_s->begin->next->data)
			find_sort_2(st_b_s);
		else
			st_b_s->begin = st_b_s->begin->next;
	}
	st_b_s->sorted.first = st_b_s->start->data;
	st_b_s->sorted.len = st_b_s->real_len + 1;
	sortedd = st_b_s->sorted;
	free(st_b_s);
	return (sortedd);
}

void	make_b_end_null(t_struct *b, int for_b)
{
	t_struct	*keep_b;
	int			i;

	i = 1;
	keep_b = b;
	while (i < for_b)
	{
		b = b->next;
		i++;
	}
	b->next = NULL;
	b = keep_b;
}

void	sorted_stay_a2(t_holder *holder, int i, int len_a)
{
	while (i > 0)
	{
		ra(&(holder->a));
		i--;
		len_a++;
	}
}

void	sorted_stay_a(t_holder *holder, t_struct2 sorted, int size)
{
	int			i;
	int			for_b;
	t_struct	*keep_b;
	int			len_a;

	i = sorted.len;
	holder->size_a = size;
	holder->size_b = 0;
	for_b = 0;
	keep_b = holder->b;
	len_a = 0;
	while (size - sorted.len + 1 > 0)
	{
		if (holder->a->data == sorted.first)
			sorted_stay_a2(holder, i, len_a);
		else
		{
			pb(holder);
			for_b++;
		}
		size--;
	}
	make_b_end_null(holder->b, for_b);
}
