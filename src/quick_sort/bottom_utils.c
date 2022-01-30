/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bottom_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:58:06 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/30 22:07:36 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	bottom_order(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_b->prev;
	if (p->prev->prev->rank < p->prev->rank)//
	{
		return (bottom_order_first(nil_a, nil_b));
	}
	else
	{
		return (bottom_order_second(nil_a, nil_b));
	}
	return (0);
}

int	bottom_order_first(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_b->prev;
	if (p->prev->rank < p->rank)
	{//123
		sort_bottom_123(nil_a, nil_b);
		return (0);
	}
	else if (p->prev->prev->rank < p->rank)
	{//132
		sort_bottom_132(nil_a, nil_b);
		return (0);
	}
	else if (p->prev->rank > p->rank)
	{//231
		sort_bottom_231(nil_a, nil_b);
		return (0);
	}
	else
	{
		return (0);
	}
}

int	bottom_order_second(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_b->prev;
	if (p->prev->prev->rank < p->rank)
	{
		sort_bottom_213(nil_a, nil_b);
		return (0);//213
	}
	else if (p->prev->prev->rank > p->rank
		&& p->prev->rank < p->rank)
	{//312
		sort_bottom_312(nil_a, nil_b);
		return (0);
	}
	else if (p->prev->rank > p->rank)
	{
		sort_bottom_321(nil_a, nil_b);
		return (0);
	}
	else
		return (0);
}
