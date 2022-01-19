/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:22:12 by akihito           #+#    #+#             */
/*   Updated: 2022/01/19 10:44:46 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
// 3個の引数は２個以内のアクションで納める。

int	arg_3(t_bi_list *nil)
{
	t_bi_list	*p;

	p = nil->next;
	if (p->rank < p->next->rank)
	{//1 < 2
		if (p->rank < p->next->next->rank)
		{
			printf("~~1~~\n");
			return (0);
		}
		else if (p->rank > p->next->next->rank)
		{
			printf("~~2~~\n");
			rra(nil);
			return (0);
		}
		printf("ソート漏れ\n");
		return (1);
	}
	else//1 > 2
	{
		if (p->rank > p->next->rank && p->next->rank < p->next->next->rank)
		{//1 > 2 && 2 < 3
			if (p->rank < p->next->next->rank)
			{//2 1 3
				printf("~~3~~\n");
				sa(nil);
				return (0);
			}
			else if (p->rank > p->next->next->rank)
			{
				printf("~~4~~\n");
				ra(nil);
				return (0);
			}
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

int	is_sorted(t_bi_list *nil)
{
	t_bi_list	*p;

	p = nil->next;//
	while (p->next != nil)
	{
		if (p->rank > p->next->rank)
		{//未ソートだったら1を返す
			return (1);
		}
		p = p->next;
	}
	return (0);
}

int	arg_2(t_bi_list *nil)
{
	t_bi_list	*p;

	p = nil->next;
	if (nil->which == A)
	{
		if (p->next->rank > p->next->next->rank)
		{
			sa(nil);
			return (0);
		}
	}
	else
	{
		if (p->next->rank < p->next->next->rank)
		{
			sb(nil);
			return (0);
		}
	}
	return (0);
}

int	arg_5(t_bi_list *nil_a, t_bi_list *nil_b)
{//yllow3を参照　rank1,2をpbする。し終わったらスタックAをソート
	t_bi_list	*p;
	int			i;

	i = 0;
	p = nil_a->next;
	printf("stack_size = %d\n",nil_a->stack_size);
	while (i < nil_a->stack_size)
	{
		if (p->rank == 1 || p->rank == 2)
		{
			pb(nil_a, nil_b);
		}
		else
		{
			ra(nil_a);
		}
		p = nil_a->next;
		i++;
		// print_stacks(nil_a, nil_b);
	}
	arg_3(nil_a);
	// print_stacks(nil_a, nil_b);
	arg_2(nil_b);
	pa(nil_a, nil_b);
	pa(nil_a, nil_b);
	return (0);
}

int	arg_3_to_6(int argc, t_bi_list *nil_a, t_bi_list *nil_b)
{
	if (argc == 4)
	{
		printf("ok\n");
		arg_3(nil_a);
	}
	else if (argc >= 6)
	{
		printf("5個\n");
		arg_5(nil_a, nil_b);
		return (0);
	}
	return (0);
}

int	operation_stack(int argc, t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p_a;
	t_bi_list	*p_b;

	p_a = nil_a;
	p_b = nil_a;
	if (argc <= 7)
	{
		if (argc == 2)
		{
			return (0);
		}
		else if (argc == 3)
		{
			printf("argc = 3\n");
			if (nil_a->next->value > nil_a->prev->value)
				sa(nil_a);
			else
			{
				printf("何もしない\n");
			}
		}
		else if (argc >= 4)
		{
			printf("argc = %d\n", argc);
			arg_3_to_6(argc, nil_a, nil_b);
			// pb(nil_a,nil_b);
			// rra(nil_a);
		}
	}
	return (0);
}