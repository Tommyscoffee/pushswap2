/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Qsort_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:40:01 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/23 20:42:51 by atomizaw         ###   ########.fr       */
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
	if ((p->rank <= 3 && p->rank >= 1) && check_bottom_3(nil_b))
	{
		printf("bwantのノード\n");
		rb(nil_b);
		return (1);
	}
	return (0);

}

int	check_bottom_3(t_bi_list *nil)//スタックbに３以下の数字しかないのに、rbするのほ防ぐ
{
	t_bi_list	*p;
	int			under_3_num;
	int			i;

	i = 0;
	p = nil->prev;
	under_3_num = 0;
	while (i < 3)
	{
		if (p->rank <= 3)
			under_3_num++;
		i++;
	}
	if (under_3_num < nil->size_now)
		return (1);
	return (0);
}
