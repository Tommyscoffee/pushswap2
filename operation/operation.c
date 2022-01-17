/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:22:12 by akihito           #+#    #+#             */
/*   Updated: 2022/01/17 13:05:40 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
// 3個の引数は２個以内のアクションで納める。

int	arg_3(t_bi_list *nil)
{
	t_bi_list	*p;

	p = nil->next;
	if (p->rank < p->next->rank)
	{
		if (p->next->rank < p->next->next->rank)
		{
			printf("~~1~~\n");
			return (0);
		}
		else if (p->next->rank < p->next->next->rank)
		{
			printf("~~2~~\n");
			sa(nil);
			ra(nil);
			return (0);
		}
		printf("ソート漏れ\n");
		return (1);
	}
	else//1 > 2
	{
		if (p->rank > p->next->rank && p->next->rank < p->next->next->rank)
		{
			printf("~~3~~\n");
			ra(nil);
			return (0);
		}
		if (p->rank < p->next->next->rank)
		{//1 < 3
			printf("~~4~~\n");
			sa(nil);
			return (0);
		}
		else if (p->rank > p->next->next->rank)
		{//1 > 3
			printf("~~5~~\n");
			sa(nil);
			rra(nil);
			return (0);
		}
	}
	return (1);
}

int	arg_3_to_5(int argc, t_bi_list *nil)
{
	if (argc == 4)
	{
		printf("ok\n");
		arg_3(nil);
	}
	return (0);
}

int	operation_stack(int argc, t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p_a;
	t_bi_list	*p_b;

	p_a = nil_a;
	p_b = nil_a;
	if (argc <= 4)
	{
		if (argc == 2)
		{
			return (0);
		}
		else if (argc == 3)
		{
			printf("argc = 3\n");
			if ( nil_a->next->value > nil_a->prev->value)
				sa(nil_a);
			else
			{
				printf("何もしない\n");
			}
		}
		else if (argc == 4)
		{
			arg_3_to_5(argc, nil_a);
			// pb(nil_a,nil_b);
			// rra(nil_a);
		}
	}
	return (0);
}