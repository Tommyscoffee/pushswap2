/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:34:03 by akihito           #+#    #+#             */
/*   Updated: 2022/01/23 18:41:06 by atomizaw         ###   ########.fr       */
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

int	bottom_to_bottom(t_bi_list *nil_a, t_bi_list *nil_b)
{
	// Bの底にrank1~3があったら、pbして、スタックAでarg_3でソートしてraを３回して底に移動させる
	t_bi_list	*p;
	int			i;

	i = 0;
	p = nil_b->prev;
	while (p != nil_b || (p->rank <= 3 && p->rank >= 1))
	{
		printf("bottom_to_bottomのwhile内\n");
		rb(nil_b);
		pa(nil_a, nil_b);
		nil_a->next->sorted = 1;//ソートが完了している者にはsorted = 1にする
		p = nil_b->prev;
		i++;
	}
	// スタックAに移った後の処理
	if (i == 1)
	{
		ra(nil_a);
	}
	else if (i == 2)
	{
		if (nil_a->next->value > nil_a->prev->value)
			sa(nil_a);
		else
			printf("bottom_to_bottomでスタックAの先頭２つがソートしなくてもそのままでおk\n");
	}
	else if (i == 3)
	{
		arg_3(nil_a);
	}
	else
		printf("XXXXXXXXXbottom_to_bottomで条件式を通りすぎているXXXXXXX\n");
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
	printf("スタックbのそこのrank1をスタックaのそこに移動させる\n");
	// while (i < 3)
	// {
		bottom_to_bottom(nil_a, nil_b);
	// 	rrb(nil_b);
	// 	pa(nil_a, nil_b);
	// 	ra(nil_a);

	// }
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
