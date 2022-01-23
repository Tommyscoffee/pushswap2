/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:34:03 by akihito           #+#    #+#             */
/*   Updated: 2022/01/23 13:07:10 by akihito          ###   ########.fr       */
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
	printf("pushhalf\n");
	printf("stack_size = %d\n", nil_a->stack_size);
	printf("pivot = %d\n", nil_a->pivot);
	while (i < nil_a->stack_size)
	{
		write(1, "p->value = ", 11);
		write(1, ft_itoa(p->value), ft_strlen(ft_itoa(p->value)));
		write(1, "\n", 1);
		if (p->rank <= nil_a->pivot)
		{
			p->status += nil_a->pivot;//pbしたノードにどのpivotでpbされたかを記録しておく
			pb(nil_a, nil_b);
			printf("pushhalfでnil_a->size_now = %d\n", nil_a->size_now);
			p->status = nil_a->pivot;
			if (is_b_want(nil_a, nil_b))
			{
				printf("==is_b_want==\n");
			}
		}
		if (!(nil_a->next->rank <= nil_a->pivot))
			ra(nil_a);
		p = nil_a->next;//これをやらないとpはスタックbにいくので,
		i++;
	}
	return (0);
}

int	Qsort(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p_b;
	size_t		i;

	i = 0;
	nil_b->pivot = (nil_b->size_now) / 2;
	if ((nil_b->size_now) % 2)
		nil_b->pivot++;
	printf("==QUICKSORT==\n");
	print_stacks(nil_a, nil_b);
	p_b = nil_b->next;
	// while (is_sorted(nil_a))
	// while ()
	// {
	// 	i = 0;
	while (i < nil_b->size_now)
	{
		printf("while\n");
		if (p_b->rank >= nil_b->pivot)
		{
			if (is_a_want(nil_a, nil_b))
			{
				pa(nil_a, nil_b);
				ra(nil_a);
				p_b = nil_b->next;
			}
			else
			{
				pa(nil_a, nil_b);
			}
		}
		p_b = nil_b->next;
		i++;
	}
	// }
	return (0);
}
