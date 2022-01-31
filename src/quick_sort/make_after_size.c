/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_after_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 22:59:00 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/31 23:52:48 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	make_after_size_a(t_bi_list *nil_a, t_bi_list *nil_b)
{
	int	after_size;

	after_size = nil_a->pivot;
	if ((nil_a->stack_size + nil_a->sorted_rank) % 2)
		after_size--;
	return (after_size);
}

int	make_after_size_b(t_bi_list *nil_a, t_bi_list *nil_b)
{
	int	after_size;

	after_size = nil_b->pivot - nil_a->sorted_rank;
	printf("make_after_size_b nil_b->pivot = %d\n", nil_b->pivot);
	// if (nil_a->pivot % 2)
	// 	after_size++;
	return (after_size);
}
