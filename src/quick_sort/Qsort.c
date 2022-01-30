/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:34:03 by akihito           #+#    #+#             */
/*   Updated: 2022/01/30 21:16:47 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	sort_set_operation(t_bi_list *nil_a)
{
	t_bi_list	*p;

	p = nil_a->next;
	p->sorted = 2;
	nil_a->sorted_rank = p->rank;
	nil_a->awant = p->rank + 1;
	ra(nil_a);
	return ;
}

void	unsort_set_operation(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_b->next;
	p->status = nil_b->pivot;
	if(nil_b->next->rank >= nil_a->awant)//スタックBをソートする時
		nil_a->awant = nil_b->next->rank;
	//ここの条件式は未完成,awantは+1をしているのに>=でいいのか？
	printf("\np->status = %d\n\n", p->status);
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

// int	bottom_to_bottom(t_bi_list *nil_a, t_bi_list *nil_b)//スタックBのサイズが５個以下なら
// {
// 	// Bの底にrank1~3があったら、pbして、スタックAでarg_3でソートしてraを３回して底に移動させる
// 	t_bi_list	*p;
// 	int			i;
// 	int			nil_b_size;

// 	nil_b_size = nil_b->size_now;
// 	i = 0;
// 	p = nil_b->prev;
// 	// スタックbは最初のpushhalfでは必ず４個以上になる
// 	// while ((nil_b_size - nil_b->size_now) < 3)
// 	// {
// 	printf("bottom while\n\n");
// 	printf("p->rank = %d\n", p->rank);
// 	printf("bottom_to_bottomのwhile内\n");
// 	if (nil_b->size_now == 4)
// 	{
// 		nil_b->next->sorted = 1;//スタックBが４つだったら、一番上はrank4だと決まっているから先にpaしてしまう。
// 		pa(nil_a, nil_b);
// 	}
// 	bottom_order(nil_a, nil_b);//スタックBの底の順番に応じてpaする
// 	set_sorted_a(nil_a, nil_b);
// 	if (nil_b_size <= 6)//スタックBが6以下だったらrbすれば最短で
// 		rb(nil_b);
// 	else
// 		rrb(nil_b);
// 	// pa(nil_a, nil_b);
// 	nil_a->next->sorted = 1;//ソートが完了している者にはsorted = 1にする
// 	p = nil_b->prev;
// 	i++;
// 	printf("何個paしたのか = %d\n", i);
// 	return (0);
// }
int	make_pivot(t_bi_list *nil_a, t_bi_list *nil_b)
{
	int	pivot;
//pivot = ps->awant + (size - 1) / 2;//syamashiさんのpivotの決め方
	printf("awant = %d\n\n", nil_a->awant);
	pivot = nil_a->awant + (nil_b->size_now) / 2;//なぜ−１するかはわかっていない
	//このpivotの決め方だと、スタックBが４以下の場合、pivotが１になってしまい、３つpaした後に１だけ戻るので奇数の時は++する方がいい
	if ((nil_b->size_now) % 2)
	{
		pivot++;
	}
	// if (nil_b->size_now % 2)
	// {//まだスタックBから半分ソートされた時のpivotは設定してない
		
	// }
	return (pivot);
}

int	make_after_size(t_bi_list *nil_a, t_bi_list *nil_b)
{
	int	after_size;

	after_size = nil_a->pivot / 2;
	if (nil_a->pivot % 2)
		after_size++;
	return (after_size);
}

int	Qsort_b(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;
	int			start_size;
	int			b_max;//スタックBの中の最大値これと、sorted_rankでpivotを決める
	int			after_size;

	b_max = nil_a->pivot;//スタックAが欲しいもの - 1
	printf("=======Qsort_b=========\n");
	while (nil_b->size_now > 3)
	{
		nil_b->pivot = make_pivot(nil_a, nil_b);
		start_size = nil_b->size_now;//push_half_aした直後のスタックBの要素数
		p = nil_b->next;
		after_size = make_after_size(nil_a, nil_b);
		printf("pivot = %d\n", nil_b->pivot);
		// while ((start_size - nil_b->size_now) < (nil_b->pivot))
		while (nil_b->size_now > after_size)
		{
			printf("awant = %d\n", nil_a->awant);
			printf("after_size = %d\n", after_size);
			printf("b_max = %d\n", b_max);
			printf("Q_sort_b_while\n\n");
			printf("pivot = %d\n", nil_b->pivot);
			if (p->rank > nil_b->pivot)
			{
				printf("unsort\n\n");
				unsort_set_operation(nil_a, nil_b);
			}// is_a_want(nil_a, nil_b);//rbする前に次のノードがawantだったらソートしちゃう
			else
				rb(nil_b);
			p = nil_b->next;
		}
	}
	printf("nil_a->next->status = %d\n", nil_a->next->status);
	bottom_order(nil_a, nil_b);
	set_sorted_a(nil_a, nil_b);
	printf("+++++++Qsort_b終了********\n");
	printf("*****nil_a->sorted_rank = %d\n",nil_a->sorted_rank);
	return (0);
}

int	pb_same_status(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;
	int			std_status;

	p = nil_a->next;
	std_status = p->status;
	// if (std_status == 0)
	// {
	// 	printf("たまたまソートれているので、次のpush_half_aにいって\n");
	// 	return (0);
	// }
	
	printf("std_status = %d\n", std_status);
	while (p->status == std_status)
	{
		printf("p->status = %d\n",p->status);
		p->status = 0;
		pb(nil_a, nil_b);
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
	push_half_a(nil_a, nil_b);
	p_b = nil_b->next;
	// while (nil_a->sorted_rank != nil_a->stack_size)
	while (i < 3)
	{
		// push_half_a_2(nil_a, nil_b);//完了
		printf("======Qsort-while=======\n");
		Qsort_b(nil_a, nil_b);
		printf("\n\n\n\n\n\n");
		// pb_same_status(nil_a, nil_b);		p_b = nil_b->next;
		i++;
	}
	return (0);
}
