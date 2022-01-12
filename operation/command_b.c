/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:41:19 by akihito           #+#    #+#             */
/*   Updated: 2022/01/12 14:50:52 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	sb(t_bi_list *nil, t_bi_list *high, t_bi_list *low)
{
	nil->next = low;
	nil->prev = high;
	low->next = high;
	low->prev = nil;
	high->next = nil;
	high->prev = low;
	return (0);
}

int	pb(t_bi_list *a, t_bi_list *b)
{
	t_bi_list	*first_a;
	t_bi_list	*first_b;
	t_bi_list	*second_a;

	if (b->next->value == -1)
		return (TRUE);
	first_a = a->next;
	first_b = b->next;
	second_a = a->next->next;
	a->next = second_a;
	second_a->prev = a;
	b->next = first_a;
	first_a->next = first_b;
	first_b->prev = first_a;
	first_a->prev = b;
	return (FALSE);
}