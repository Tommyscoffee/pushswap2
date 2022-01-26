/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_top_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 21:02:36 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/26 22:04:03 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	sort_top_3_a(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_a->next;
	if (p->rank < p->next->rank)//
	{
		return (sort_top_3_a_first(nil_a, nil_b));
	}
	else
	{
		return (sort_top_3_a_second(nil_a, nil_b));
	}
	return (0);
}

int	sort_top_3_a_first(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_a->next;
	if (p->next->rank < p->next->next->rank)
	{//123
		ra(nil_a);
		ra(nil_a);
		ra(nil_a);
	}
	else if (p->rank < p->next->next->rank)
	{//132
		ra(nil_a);
		sa(nil_a);
		ra(nil_a);
		ra(nil_a);
	}
	else if (p->rank > p->next->next->rank)
	{//231
		pb(nil_a, nil_b);
		sa(nil_a);
		ra(nil_a);
		pb(nil_a, nil_b);
		ra(nil_a);
		ra(nil_a);
	}
	return (1);

}

int	sort_top_3_a_second(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;
	p = nil_a->next;

	if (p->rank < p->next->next->rank)
	{//213
		sa(nil_a);
		ra(nil_a);
		ra(nil_a);
		ra(nil_a);
	}
	else if (p->rank > p->next->next->rank
		&& p->next->rank < p->next->next->rank)
	{//312
		sa(nil_a);
		ra(nil_a);
		sa(nil_a);
		ra(nil_a);
		ra(nil_a);
	}
	else if (p->rank > p->next->next->rank)
	{//321
		pb(nil_a, nil_b);
		sa(nil_a);
		ra(nil_a);
		ra(nil_a);
		pa(nil_a, nil_b);
		ra(nil_a);
	}
	return (0);
}
