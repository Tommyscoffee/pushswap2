/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Qsort_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:40:01 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/22 22:33:08 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	iswant(t_bi_list *nil_a, t_bi_list *nil_b)
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
