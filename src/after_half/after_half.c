// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   after_half.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/01/31 22:54:22 by atomizaw          #+#    #+#             */
// /*   Updated: 2022/01/31 23:27:15 by atomizaw         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../includes/pushswap.h"

// void	after_half(t_bi_list *nil_a, t_bi_list *nil_b)
// {
// 	t_bi_list	*p;

// 	p = nil_a->next;
// 	push_b(nil_a, nil_b);
// }

// int	after_push_b(t_bi_list *nil_a, t_bi_list *nil_b)
// {
// 	is_a_want(nil_a, nil_b);
// 	while (!b_sequence(nil_a, nil_b))
// 	{
// 		pb(nil_a, nil_b);
// 	}
	// return ;
// }

// int	until_b_sequence(t_bi_list *nil_a, t_bi_list *nil_b)
// {
// 	t_bi_list	*p;
// 	int			i;
// 	int			b_min;

// 	b_min = nil_a->sorted_rank + 1;//スタックBに入る最小値
// 	i = b_min;
// 	p = nil_b->next;
// 	if (nil_b->next->rank > nil_b->bmax)
// 	{
// 		nil_b->bmax = nil_b->next->rank;
// 	}
// 	while (i < nil_b->bmax)
// 	{
// 		while (p->next != nil_b)
// 		{
// 			if (i == p->rank)
// 			{
// 				i++;
// 				break;
// 			}
// 		}
// 	}
// }