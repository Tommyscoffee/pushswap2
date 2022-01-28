/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:34:03 by akihito           #+#    #+#             */
/*   Updated: 2022/01/29 02:01:03 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	sort_set_operation(t_bi_list *nil_a)
{
	t_bi_list	*p;

	p = nil_a->next;
	p->sorted = 2;
	nil_a->sorted_rank = p->rank;
	ra(nil_a);
	return ;
}

void	unsort_set_operation(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_b->next;
	p->status = nil_b->pivot;
	printf("\np->status = %d\n\n",p->status);
	pa(nil_a, nil_b);
	return ;
}

int	set_sorted_a(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_a->next;
	while (nil_a->next->rank == nil_a->sorted_rank + 1)
	{
		sort_set_operation(nil_a);
		p = nil_a->next;
	}
	if (is_sorted(nil_a))
	{
		ft_sortdone();
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
	// while ((nil_b_size - nil_b->size_now) < 3)
	// {
	printf("bottom while\n\n");
	printf("p->rank = %d\n", p->rank);
	printf("bottom_to_bottomのwhile内\n");
	if (nil_b->size_now == 4)
	{
		nil_b->next->sorted = 1;//スタックBが４つだったら、一番上はrank4だと決まっているから先にpaしてしまう。
		pa(nil_a, nil_b);
	}
	bottom_order(nil_a, nil_b);//スタックBの底の順番に応じてpaする
	set_sorted_a(nil_a, nil_b);
	if (nil_b_size <= 6)//スタックBが6以下だったらrbすれば最短で
		rb(nil_b);
	else
		rrb(nil_b);
	// pa(nil_a, nil_b);
	nil_a->next->sorted = 1;//ソートが完了している者にはsorted = 1にする
	p = nil_b->prev;
	i++;
	printf("何個paしたのか = %d\n", i);
	return (0);
}

int	Qsort_b(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;
	int			start_size;
	int			b_max;//スタックBの中の最大値これと、sorted_rankでpivotを決める

	b_max = nil_a->pivot;
	printf("=======Qsort_b=========\n");
	start_size = nil_b->size_now;//push_half_aした直後のスタックBの要素数
	p = nil_b->next;

	if ((nil_b->size_now) % 2)
		nil_b->pivot++;
	printf("pivot = %d\n", nil_b->pivot);
	while (nil_b->size_now > 3)
	{
		nil_b->pivot = ((b_max) / 2) + nil_a->sorted_rank;//このpivotを含んだrankが来る
		while ((start_size - nil_b->size_now) < (nil_b->pivot) / 2)
		{
			if (p->rank > nil_b->pivot)
			{
				unsort_set_operation(nil_a, nil_b);
			}// is_a_want(nil_a, nil_b);//rbする前に次のノードがawantだったらソートしちゃう
			else
				rb(nil_b);
			p = nil_b->next;
		}
	}
	printf("=============Qsort_b終了===========\n");
	//Bをソートして３個以下になったら
	// setsortedの後無駄にraしてごちゃごちゃになってる
	bottom_order(nil_a, nil_b);
	set_sorted_a(nil_a, nil_b);
	printf("+++++++Qsort_b終了********\n");
	printf("*****nil_a->sorted_rank = %d\n",nil_a->sorted_rank);
	return (0);
}

int	push_same_status(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;
	int			std_status;

	p = nil_a->next;
	std_status = p->status;
	printf("std_status = %d\n", std_status);
	while (p->status == std_status)
	{
		p->status = 0;
		pa(nil_a, nil_b);
		p = nil_a->next;
	}
	return (0);
}

int	Qsort(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p_b;
	size_t		i;
	int			prev_pivot;

	prev_pivot = nil_b->pivot;
	i = 0;
	nil_b->pivot = ((nil_b->size_now) / 2) + nil_a->sorted_rank;
	if ((nil_b->size_now) % 2)
		nil_b->pivot++;
	printf("==QUICKSORT==\n");
	// sleep(300);
	p_b = nil_b->next;
	push_half_a(nil_a, nil_b);
	while (nil_a->sorted_rank != nil_a->stack_size)
	{
		printf("======Qsort-while=======\n");
		Qsort_b(nil_a, nil_b);
		push_same_status(nil_a, nil_b);
		// if (p_b->rank >= nil_b->pivot)
		// {
		// 	if (is_a_want(nil_a, nil_b))
		// 	{
		// 		pa(nil_a, nil_b);
		// 		ra(nil_a);
		// 		p_b = nil_b->next;
		// 	}
		// 	else
		// 	{
		// 		pa(nil_a, nil_b);
		// 	}
		// }
		p_b = nil_b->next;
		i++;
	}
		// printf("再帰入ってます\n");
		// Qsort(nil_a, nil_b);
	// }
	return (0);
}
