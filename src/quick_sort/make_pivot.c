/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 22:45:24 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/31 18:37:23 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	make_pivot_a(t_bi_list *nil_a, t_bi_list *nil_b)
{
	int	pivot;
//pivot = ps->awant + (size - 1) / 2;//syamashiさんのpivotの決め方
	printf("awant = %d\n\n", nil_a->awant);
	pivot = (((nil_a->stack_size + nil_a->sorted_rank) / 2));
	printf("sorted_rank = %d\n", nil_a->sorted_rank);
	printf("nil_a->stack_size = %d\n", nil_a->stack_size / 2);
	printf("pivot = %d\n", pivot);
	if ((nil_a->stack_size + nil_a->sorted_rank) % 2)
		pivot++;
	return (pivot);
}


int	make_pivot_b(t_bi_list *nil_a, t_bi_list *nil_b)
{
	int	pivot;
//pivot = ps->awant + (size - 1) / 2;//syamashiさんのpivotの決め方
	printf("awant = %dもともとpivotはawantを使っていたが、ダメなのでsorted_rankに変更\n\n", nil_a->awant);
	printf("sorted_rank = %d\n", nil_a->sorted_rank);
	pivot = nil_a->sorted_rank + (nil_b->size_now) / 2;//なぜ−１するかはわかっていない
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
