/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:34:03 by akihito           #+#    #+#             */
/*   Updated: 2022/01/24 17:27:15 by atomizaw         ###   ########.fr       */
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

int	set_sorted(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_a->next;
	while (p->sorted == 1)
	{
		if (p->sorted == 1)
		{
			p->sorted = 2;
			ra(nil_a);
		}
		p = nil_a->next;
	}
	return (0);
}

int	bottom_to_bottom(t_bi_list *nil_a, t_bi_list *nil_b)//スタックBのサイズが５個以下なら
{
	// Bの底にrank1~3があったら、pbして、スタックAでarg_3でソートしてraを３回して底に移動させる
	t_bi_list	*p;
	int			i;
	int			nil_b_size;

	nil_b_size = nil_b->size_now;
	i = 0;
	p = nil_b->prev;
	// スタックbは最初のpushhalfでは必ず４個以上になる
	while ((nil_b_size - nil_b->size_now) < 3)
	{
		printf("bottom while\n\n");
		// if (nil_b->next->rank >= 1 && nil_b->next->rank <= 3)
		// {
		// 	pa(nil_a, nil_b);
		// }
		// else
		// {
			// if (nil_b_size <= 6)またbottom_orderの条件分岐を作り直すのはめんどくさいから、全てrrbで済ませる
			// {
				
			// }
		printf("p->rank = %d\n", p->rank);
		printf("bottom_to_bottomのwhile内\n");
		bottom_order(nil_a, nil_b);//スタックBの底の順番に応じてpaする
		set_sorted(nil_a, nil_b);
		if (nil_b_size <= 6)//スタックBが6以下だったらrbすれば最短で
			rb(nil_b);
		else
			rrb(nil_b);
		pa(nil_a, nil_b);
		// }
		nil_a->next->sorted = 1;//ソートが完了している者にはsorted = 1にする
		p = nil_b->prev;
		i++;
	}
	printf("何個paしたのか = %d\n", i);
	// スタックAに移った後の処理
	if (i == 1)
	{
		ra(nil_a);
	}
	else if (i == 2)
	{
		if (nil_a->next->value < nil_a->prev->value)
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
	printf("スタックbのそこのrank1をスタックaのそこに移動させる\n");
	bottom_to_bottom(nil_a, nil_b);
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
	return (0);
}
