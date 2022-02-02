/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_half.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:54:22 by atomizaw          #+#    #+#             */
/*   Updated: 2022/02/02 20:01:37 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	after_half(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_a->next;
	printf("after_half\n");
	after_push_b(nil_a, nil_b);
	while (nil_a->size_now != nil_a->stack_size)
	{
		printf("nil_a->sorted_rank = %d\n", nil_a->sorted_rank);
		printf("nil_a->stack_size = %d\n", nil_a->stack_size);
		printf("======Qsort-while=======\n");
		Qsort_b(nil_a, nil_b);
		printf("\n\n\n\n\n\n");
		pb_same_status(nil_a, nil_b);
	}
	return ;
}

int	after_push_b(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_a->next;
	nil_b->bmax = nil_a->sorted_rank;//until_b_sequenceで使うのでsoretedrankで初期化
	// if (nil_a->awant == p->rank)
	// {
	// 	set_sorted_a(nil_a, nil_b);
	// }
	while (!until_b_sequence(nil_a, nil_b) && nil_a->next->sorted < 1) 
	{
		printf("until_b_sequence\n\n");
		set_sorted_a(nil_a, nil_b);//最適化ここでnil_a->sorted_rankが変動する
		if (nil_a->next->sorted != 2)//set_sorted_aでraした次が1である時に勝手にpbしてしまう。
			pb(nil_a, nil_b);
	}
	printf("\n\n 連続を検出\n\n");
	return (0);
}

int	until_b_sequence(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;
	int			i;

	p = nil_a->next;
	// bmax = nil_a->sorted_rank;//最低でもbmaxはsorted_rankより大きい
	if (nil_a->next->rank > nil_b->bmax)
		nil_b->bmax = nil_a->next->rank;
	printf("bmax = %d\n", nil_b->bmax);
	i = nil_a->sorted_rank + 1;//連続かを見るカウント変数
	while (i < nil_b->size_now)
	{
		while (p != nil_b)//毎回スタックBを全部見る
		{
			if (i == (p->rank - nil_a->sorted_rank))
			{
				i++;
				break;
			}
			p = p->next;
		}
	}
	if (i == nil_b->bmax)
		return (1);
	return (0);
}


// int	until_b_sequence(t_bi_list *nil_a, t_bi_list *nil_b)
// {
// 	t_bi_list	*p;
// 	int			target;
// 	int			prev;
// 	int			i;
// 	int			array[nil_b->size_now];

	
// 	i = 0;
// 	prev = 0;
// 	p = nil_a->next;
// 	if (nil_a->next->rank > nil_b->bmax)
// 		nil_b->bmax = nil_a->next->rank;
// 	target = nil_a->sorted_rank + 1;//連続かを見るカウント変数
// 	printf("bmax = %d\n", nil_b->bmax);
// 	printf("target = %d\n", target);
// 	while (i < nil_b->size_now)
// 	{
// 		printf("while\n");
// 		prev = target;
// 		while (p != nil_a)//毎回スタックBを全部見る
// 		{
// 			printf("target = %d\n", target);
// 			printf("p->rank = %d\n", p->rank);
// 			if (target == p->rank)
// 			{
// 				target++;
// 				break ;
// 			}
// 			else
// 				p = p->next;
// 		}
// 		if (target == prev)
// 		{
// 			printf("連続ではありません\n");
// 			return (0);
// 		}
// 		i++;
// 	}
// 	if (target == nil_b->bmax)
// 	{
// 		printf("連続です\n\n\n\n");
// 		exit(0);
// 		return (1);
// 	}
// 	return (1);
// }
