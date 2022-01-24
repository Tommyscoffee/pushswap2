/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_half.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:48:46 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/24 20:01:29 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	push_half(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;
	size_t		i;

	i = 0;
	p = nil_a->next;
	nil_a->pivot = (nil_a->stack_size) / 2;
	if (nil_a->stack_size % 2)
		nil_a->pivot++;
	printf("===pushhalfに入りました====\n");
	printf("・stack_size = %d\n", nil_a->stack_size);
	printf("・pivot = %d\n", nil_a->pivot);
	// while (i < nil_a->stack_size && nil_a->size_now >= ((nil_a->stack_size) / 2))
	while (nil_a->size_now > ((nil_a->stack_size) / 2))
	{
		if (p->rank <= nil_a->pivot)
		{
			p->status += nil_a->pivot;//pbしたノードにどのpivotでpbされたかを記録しておく
			pb(nil_a, nil_b);
			// printf("pushhalfでnil_a->size_now = %d\n", nil_a->size_now);``
			p->status = nil_a->pivot;
			if (is_b_want(nil_a, nil_b))//ここでスタックBで底にあるべきものをそこに移動させている
			{
				printf("==is_b_want==\n");
			}
		}
		if (nil_a->next->rank > nil_a->pivot
			&& nil_a->size_now > ((nil_a->stack_size) / 2))
			ra(nil_a);
		p = nil_a->next;//これをやらないとpはスタックbにいくので,
		i++;
	}
	return (0);
}

int	push_half2(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;
	size_t		i;

	i = 0;
	p = nil_a->next;
	nil_a->pivot = ((nil_a->stack_size - nil_a->prev->rank) / 2);
	if ((nil_a->stack_size - nil_a->prev->rank) % 2)
		nil_a->pivot++;
	printf("===pushhalf2に入りました====\n");
	printf("・stack_size = %d\n", nil_a->stack_size);
	printf("・pivot = %d\n", nil_a->pivot);
	// while (i < nil_a->stack_size && nil_a->size_now >= ((nil_a->stack_size) / 2))
	while (nil_a->size_now > ((nil_a->stack_size) / 2))
	{
		if (p->rank <= nil_a->pivot)
		{
			p->status += nil_a->pivot;//pbしたノードにどのpivotでpbされたかを記録しておく
			pb(nil_a, nil_b);
			// printf("pushhalfでnil_a->size_now = %d\n", nil_a->size_now);``
			p->status = nil_a->pivot;
			if (is_b_want(nil_a, nil_b))//ここでスタックBで底にあるべきものをそこに移動させている
			{
				printf("==is_b_want==\n");
			}
		}
		if (nil_a->next->rank > nil_a->pivot
			&& nil_a->size_now > ((nil_a->stack_size) / 2))
			ra(nil_a);
		p = nil_a->next;//これをやらないとpはスタックbにいくので,
		i++;
	}
	return (0);
}
