/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:34:03 by akihito           #+#    #+#             */
/*   Updated: 2022/01/20 23:05:47 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	push_half(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_a->next;
	
}

int	Qsort(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	nil_a->pivot = (nil_a->stack_size) / 2;
	printf("QUICKSORT\n");
	printf("stack_size %d\n", nil_a->stack_size);
	p = nil_a->next;
	while (p != nil_a)
	{
		printf("while\n");
		if (p->rank <= nil_a->pivot)
		{
			pb(nil_a, nil_b);
		}
		p = p->next;
	}
	return (0);
}
