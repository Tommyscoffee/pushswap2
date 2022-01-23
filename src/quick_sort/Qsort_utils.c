/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Qsort_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:40:01 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/23 01:28:47 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	is_a_want(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*bottom;
	t_bi_list	*p_b;

	p_b		= nil_b->next;
	bottom	= nil_a->prev;
	if (p_b->rank == (bottom->rank - 1))
	{
		printf("awantのノード\n");
		p_b->status = nil_b->pivot;
		pa(nil_a, nil_b);
		return (1);
	}
	return (0);
}

int	is_b_want(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_b->next;
	if (p->rank == 1)
	{
		rb(nil_b);
		return (1);
	}
	return (0);

}