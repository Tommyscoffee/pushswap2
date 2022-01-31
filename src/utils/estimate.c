/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   estimate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:56:48 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/31 14:00:05 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	estimate_stack_a_sorted(t_bi_list *nil_a)
{
	t_bi_list	*p;
	int			sorted_from_nil_a;

	sorted_from_nil_a = 0;
	p = nil_a->next;
	while (p->rank != nil_a->sorted)
	{
		sorted_from_nil_a++;
		p = p->next;
	}
	return (sorted_from_nil_a);
}
