/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_bottom_second.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:17:08 by akihito           #+#    #+#             */
/*   Updated: 2022/01/31 22:31:03 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	sort_bottom_213(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_b->prev;
	rrb(nil_b);
	pa(nil_a, nil_b);
	rrb(nil_b);
	rrb(nil_b);
	pa(nil_a, nil_b);
	pa(nil_a, nil_b);
	return ;
}

void	sort_bottom_312(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_b->prev;
	rrb(nil_b);
	rrb(nil_b);
	rrb(nil_b);
	pa(nil_a, nil_b);
	sb(nil_b);
	pa(nil_a, nil_b);
	pa(nil_a, nil_b);
	return ;
}

void	sort_bottom_321(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_b->prev;
	// rrb(nil_b);
	// rrb(nil_b);
	// rrb(nil_b);
	pa(nil_a, nil_b);
	pa(nil_a, nil_b);
	pa(nil_a, nil_b);
	return ;
}
