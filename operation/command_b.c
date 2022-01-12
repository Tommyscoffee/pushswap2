/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:41:19 by akihito           #+#    #+#             */
/*   Updated: 2022/01/12 21:16:11 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	sb(t_bi_list *a)
{
	t_bi_list *high;
	t_bi_list *low;

	if (a->next->value == -1)
		return (TRUE);
	write(1, "[sb]\n", 5);
	a->next = low;
	a->prev = high;
	low->next = high;
	low->prev = a;
	high->next = a;
	high->prev = low;
	show_list(a);
	return (0);
}

int	pb(t_bi_list *a, t_bi_list *b)
{
	t_bi_list	*first_a;
	t_bi_list	*first_b;
	t_bi_list	*second_a;

	if (a->next->value == -1)
		return (TRUE);
	write(1, "[pb]\n", 5);
	first_a = a->next;
	first_b = b->next;
	second_a = a->next->next;
	a->next = second_a;
	second_a->prev = a;
	b->next = first_a;
	first_a->next = first_b;
	first_b->prev = first_a;
	first_a->prev = b;
	print_stacks(a,b);
	return (FALSE);
}

int	rb(t_bi_list *nil)
{
	t_bi_list	*first;
	t_bi_list	*second;
	t_bi_list	*bottom;

	if (nil->next->next->value == -1)//スタックが空か１つだったらエラー
		return (TRUE);
	write(1, "[rb]\n", 5);
	first = nil->next;
	second = nil->next->next;
	bottom = nil->prev;
	nil->next = second;
	second->prev = nil;
	nil->prev = first;
	first->next = nil;
	first->prev = bottom;
	bottom->next = first;
	show_list(nil);
	return (FALSE);
}

int	rrb(t_bi_list *nil)
{
	t_bi_list	*bottom;
	t_bi_list	*first;
	t_bi_list	*second;

	if (nil->next->next->value == -1)//スタックが空か１つだったらエラー
		return (TRUE);
	write(1, "[rrb]\n", 6);
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