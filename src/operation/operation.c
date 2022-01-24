/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:22:12 by akihito           #+#    #+#             */
/*   Updated: 2022/01/19 20:47:54 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
// 3個の引数は２個以内のアクションで納める。

int	arg_3_b(t_bi_list *nil_b)
{
	t_bi_list	*p;

	p = nil_b->next;
	if (p->rank > p->next->rank)
	{//1 > 2
		printf("sort_3_first\n");
		if (sort_3_b_first(nil_b))
			return (1);
		return (0);
	}
	else//1 > 2
	{
		if (sort_3_b_second(nil_b))
			return (1);
		return (0);
	}
	return (1);
}

int	arg_2(t_bi_list *nil)
{
	t_bi_list	*p;

	p = nil->next;
	if (nil->which == A)
	{
		if (p->rank > p->next->rank)
		{
			sa(nil);
			return (0);
		}
	}
	else
	{
		if (p->rank < p->next->rank)
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
	printf("stack_size = %d\n", nil_a->stack_size);
	while (i < nil_a->stack_size)
	{
		printf("stack_size = %d\n", nil_a->stack_size);
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
	arg_2(nil_b);
	print_stacks(nil_a, nil_b);
	pa(nil_a, nil_b);
	pa(nil_a, nil_b);
	return (0);
}

int	arg_6(t_bi_list *nil_a, t_bi_list *nil_b)
{//yllow3を参照　rank1,2をpbする。し終わったらスタックAをソート
	t_bi_list	*p;
	size_t			i;

	i = 0;
	p = nil_a->next;
	while (i < nil_a->stack_size)
	{
		if (p->rank == 1 || p->rank == 2 || p->rank == 3)
		{
			pb(nil_a, nil_b);
		}
		else
		{
			ra(nil_a);//raすると、pのノードが一番後ろに来て、p=p->next　== nil_aになってしまうので、条件式にp != nil_aを入れられない。
		}
		p = nil_a->next;
		i++;
	}
	arg_3(nil_a);
	arg_3_b(nil_b);
	while (nil_a->next->rank != 1)
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
	else if (argc == 5)
	{
		arg_4(nil_a, nil_b);
	}
	else if (argc == 6)
	{
		printf("5個\n");
		arg_5(nil_a, nil_b);
		return (0);
	}
	else if (argc == 7)
	{
		printf("6個\n");
		arg_6(nil_a, nil_b);
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
		else if (argc >= 4 && argc <= 7)
		{
			printf("argc = %d\n", argc);
			arg_3_to_6(argc, nil_a, nil_b);
		}
	}
	else
	{
		// push_half(nil_a, nil_b);
		// printf("==pushhalf終了==\n");
		Qsort(nil_a, nil_b);
		printf("==最終出力==\n");
		print_stacks(nil_a, nil_b);
	}
	return (0);
}
