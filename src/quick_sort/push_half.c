/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_half.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:48:46 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/30 23:03:40 by atomizaw         ###   ########.fr       */
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

int	check_rest_a(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_b->prev;
	printf("=======check_rest_a=========\n");
	printf("nil_a->size_now = %d\n", nil_a->size_now);
	printf("il_a->sorted_rank = %d\n", nil_a->sorted_rank);

	// if (nil_a->size_now - nil_a->sorted_rank == 0)//スタックAのソートされてない残りが３つ以下だったらルールベース
	if (nil_a->size_now - nil_a->sorted_rank == 2)
	{
		if (nil_a->next->rank < nil_a->next->next->rank)
			sa(nil_a);
		ra(nil_a);
		ra(nil_a);
	}
	else if (nil_a->size_now - nil_a->sorted_rank == 3)//スタックAのソートされてない残りが３つ以下だったらルールベース
	{
		// bottom_to_bottom(nil_a, nil_b);
		sort_top_3_a(nil_a, nil_b);
		// nil_b->sorted = 1;
		// pb(nil_a, nil_b);
		// nil_b->sorted = 1;
		// pb(nil_a, nil_b);
		// nil_b->sorted = 1;
		// pb(nil_a, nil_b);
		// // if (p->prev->prev->rank < p->prev->rank)//
		// {
		// 	return (bottom_order_first(nil_a, nil_b));
		// }
		// else
		// {
		// 	return (bottom_order_second(nil_a, nil_b));
		// }
		// bottom_order(nil_a, nil_b);
		// set_sorted(nil_a, nil_b);
	}
	if (!is_sorted(nil_a))
	{
		printf("だめ\n");
	}
	return (0);
}

// int	push_half2(t_bi_list *nil_a, t_bi_list *nil_b)
// {//まだ一回もpbされてない塊の半分をpbする関数
// 	t_bi_list	*p;
// 	size_t		i;

// 	i = 0;
// 	p = nil_a->next;
// 	nil_a->pivot = ((nil_a->stack_size) / 2 + nil_a->sorted_rank);
// 	if ((nil_a->stack_size - nil_a->sorted_rank) % 2)
// 		nil_a->pivot++;
// 	printf("===pushhalf2に入りました====\n");
// 	printf("・stack_size = %d\n", nil_a->stack_size);
// 	printf("sroted_rank = %d\n", nil_a->sorted_rank);
// 	printf("・pivot = %d\n", nil_a->pivot);
// 	sleep(1);
// 	// while (i < nil_a->stack_size && nil_a->size_now >= ((nil_a->stack_size) / 2))
// 	// if (check_rest_a(nil_a, nil_b))
// 	// {//スタックAのソートされていない残りが３つだったらルールベース
// 	// 	return (1);
// 	// }
// 	while (nil_a->size_now > ((nil_a->stack_size - nil_a->sorted_rank) / 2))
// 	{
// 		if (p->rank <= nil_a->pivot)
// 		{
// 			p->status = 0;//pbするときはstatusを初期化
// 			pb(nil_a, nil_b);
// 			// printf("pushhalfでnil_a->size_now = %d\n", nil_a->size_now);``
// 			if (is_a_want(nil_a, nil_b))
// 			{
				
// 			}
// 			if (is_b_want(nil_a, nil_b))//ここでスタックBで底にあるべきものをそこに移動させている
// 			{
// 				printf("==is_b_want==\n");
// 			}
// 		}
// 		if (nil_a->next->rank > nil_a->pivot
// 			&& nil_a->size_now > ((nil_a->stack_size) / 2))
// 			ra(nil_a);
// 		p = nil_a->next;//これをやらないとpはスタックbにいくので,
// 		i++;
// 	}
// 	return (0);
// }

int	push_half_a_2(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;
	size_t		i;
	int			after_a_size;

	i = 0;
	p = nil_a->next;
	nil_a->pivot = make_pivot_a(nil_a, nil_b);
	after_a_size = make_after_size_a(nil_a, nil_b);
	printf("===pushhalf_aに入りました====\n");
	printf("・stack_size = %d\n", nil_a->stack_size);
	printf("・pivot = %d\n", nil_a->pivot);
	// while (i < nil_a->stack_size && nil_a->size_now >= ((nil_a->stack_size) / 2))
	while (nil_a->size_now > after_a_size)
	{//奇数個のとき、pbする数が一個少ない　しかし、>=にすると偶数個のとき無限ループする
		printf("・stack_size = %d\n", nil_a->stack_size);
		printf("・after_a_size = %d\n", after_a_size);
		printf("・size_now = %d\n", nil_a->size_now);
		printf("・p->rank = %d\n", p->rank);
		printf("・pivot = %d\n", nil_a->pivot);
		printf("sorted_rank = %d\n", nil_a->sorted_rank);
		if (p->rank <= nil_a->pivot)//pivotを含んだものがスタックBに渡されている
			pb(nil_a, nil_b);
		if (nil_a->next->rank > nil_a->pivot && nil_a->size_now > after_a_size)
			ra(nil_a);
		p = nil_a->next;
	}
	printf("------pushhalf終了---------\n");
	return (0);
}

int	push_half_a(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;
	size_t		i;
	int			after_a_size;

	i = 0;
	p = nil_a->next;
	nil_a->pivot = ((nil_a->size_now) / 2) + nil_a->sorted_rank;
	after_a_size = nil_a->pivot;
	if ((nil_a->size_now) % 2)
		nil_a->pivot++;
	printf("===pushhalf_aに入りました====\n");
	printf("・stack_size = %d\n", nil_a->stack_size);
	printf("・pivot = %d\n", nil_a->pivot);
	// while (i < nil_a->stack_size && nil_a->size_now >= ((nil_a->stack_size) / 2))
	while (nil_a->size_now > after_a_size)
	{//奇数個のとき、pbする数が一個少ない　しかし、>=にすると偶数個のとき無限ループする
		printf("・stack_size = %d\n", nil_a->stack_size);
		printf("・size_now = %d\n", nil_a->size_now);
		printf("・p->rank = %d\n", p->rank);
		printf("・pivot = %d\n", nil_a->pivot);
		printf("sorted_rank = %d\n", nil_a->sorted_rank);
		if (p->rank <= nil_a->pivot)//pivotを含んだものがスタックBに渡されている
			pb(nil_a, nil_b);
		if (nil_a->next->rank > nil_a->pivot && nil_a->size_now > after_a_size)
			ra(nil_a);
		p = nil_a->next;
	}
	printf("------pushhalf終了---------\n");
	return (0);
}

int	push_half_b(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;
	size_t		i;
	int			start_size;

	start_size = nil_b->size_now;
	i = 0;
	p = nil_b->next;
	printf("===push_half_bに入りました====\n");
	printf("・start_size = %d\n", nil_b->size_now);
	printf("・pivot = %d\n", nil_b->pivot);
	// while (i < nil_a->stack_size && nil_a->size_now >= ((nil_a->stack_size) / 2))
	while (nil_a->size_now > (start_size / 2) + nil_a->sorted_rank)
	{//set_sortedしても必要個数pbする。
		set_sorted_a(nil_a, nil_b);
		if (p->rank <= nil_a->pivot)//pivotを含んだものがスタックBに渡されている
		{
			pb(nil_a, nil_b);
			// printf("pushhalfでnil_a->size_now = %d\n", nil_a->size_now);
		}
		if (nil_a->next->rank > nil_a->pivot
			&& nil_a->size_now > ((nil_a->stack_size) / 2))
			ra(nil_a);
		p = nil_a->next;//これをやらないとpはスタックbにいくので,
	}
}