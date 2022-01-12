/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:00:36 by akihito           #+#    #+#             */
/*   Updated: 2022/01/12 14:41:30 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	sa(t_bi_list *nil, t_bi_list *high, t_bi_list *low)
{
	nil->next = low;
	nil->prev = high;
	low->next = high;
	low->prev = nil;
	high->next = nil;
	high->prev = low;
	return (0);
}

int	pa(t_bi_list *a, t_bi_list *b)
{
	t_bi_list	*first_a;
	t_bi_list	*first_b;
	t_bi_list	*second_b;

	if (b->next->value == -1)
		return (TRUE);
	first_a = a->next;
	first_b = b->next;
	second_b = b->next->next;
	b->next = second_b;
	second_b->prev = b;
	a->next = first_b;
	first_b->next = first_a;
	first_a->prev = first_b;
	first_b->prev = a;
	return (FALSE);
}

int	ra(t_bi_list *nil)
{
	t_bi_list	*first;
	t_bi_list	*second;
	t_bi_list	*bottom;

	if (nil->next->next->value == -1)//スタックが空か１つだったらエラー
		return (TRUE);
	first = nil->next;
	second = nil->next->next;
	bottom = nil->prev;
	nil->next = second;
	second->prev = nil;
	nil->prev = first;
	first->next = nil;
	first->prev = bottom;
	bottom->next = first;
	return (FALSE);
}

int	rra(t_bi_list *nil)
{
	t_bi_list	*bottom;
	t_bi_list	*first;
	t_bi_list	*second;

	if (nil->next->next->value == -1)//スタックが空か１つだったらエラー
		return (TRUE);
	bottom = nil->prev;
	first = nil->next;
	second = nil->prev->prev;
	nil->prev = second;
	second->next = nil;
	bottom->prev = nil;
	bottom->next = first;
	nil->next = bottom;
	bottom->next = first;
	first->prev = bottom;
	return (FALSE);
}