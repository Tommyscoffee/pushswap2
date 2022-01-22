/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:34:03 by akihito           #+#    #+#             */
/*   Updated: 2022/01/22 16:15:52 by akihito          ###   ########.fr       */
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
	nil_a->size_now = nil_a->stack_size;
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
			pb(nil_a, nil_b);
			printf("pushhalfでnil_a->size_now = %d\n", nil_a->size_now);
			p->status = nil_a->pivot;
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
