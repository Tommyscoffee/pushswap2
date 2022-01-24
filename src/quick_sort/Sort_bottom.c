/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_bottom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:05:12 by akihito           #+#    #+#             */
/*   Updated: 2022/01/24 15:11:07 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	sort_bottom_123(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_b->prev;
	rrb(nil_b);
	pa(nil_a, nil_b);
	rrb(nil_b);
	pa(nil_a, nil_b);
	rrb(nil_b);
	pa(nil_a, nil_b);
	return ;
}

void	sort_bottom_132(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_b->prev;
	rrb(nil_b);
	rrb(nil_b);
	pa(nil_a, nil_b);
	pa(nil_a, nil_b);
	rrb(nil_b);
	pa(nil_a, nil_b);
	return ;
}

void	sort_bottom_231(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_b->prev;
	rrb(nil_b);
	rrb(nil_b);
	pa(nil_a, nil_b);
	rrb(nil_b);
	pa(nil_a, nil_b);
	pa(nil_a, nil_b);
	return ;
}
