/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:41:19 by akihito           #+#    #+#             */
/*   Updated: 2022/01/31 16:33:26 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	sb(t_bi_list *b)
{
	t_bi_list *first;
	t_bi_list *second;
	t_bi_list *third;

	if (b->next->next == b)
	{
		write(1,"no\n",3);
		return (TRUE);
	}
	write(STDOUT_FILENO, RED, ft_strlen(RED));
	write(STDOUT_FILENO, "__[sb]__\n", 9);
	write(STDOUT_FILENO, END, ft_strlen(END));
	first = b->next;
	second = b->next->next;
	third = b->next->next->next;
	b->next = second;
	second->next = first;
	first->next = third;
	third->prev = first;
	first->prev = second;
	second->prev = b;
	command_num++;
	return (0);
}

int	pb(t_bi_list *a, t_bi_list *b)
{
	t_bi_list	*first_a;
	t_bi_list	*first_b;
	t_bi_list	*second_a;

	if (a->next == a)
	{
		printf("pbエラーー\n");
		return (TRUE);
	}
	write(STDOUT_FILENO, RED, ft_strlen(RED));
	write(STDOUT_FILENO, "__[pb]__\n", 9);
	write(STDOUT_FILENO, END, ft_strlen(END));
	a->size_now--;
	b->size_now++;
	first_a = a->next;
	first_b = b->next;
	second_a = a->next->next;
	a->next = second_a;
	second_a->prev = a;
	b->next = first_a;
	first_a->next = first_b;
	first_b->prev = first_a;
	first_a->prev = b;
	// printf("nil_a->size_now = %d\n", a->size_now);
	// printf("nil_b->size_now = %d\n", b->size_now);
	command_num++;
	print_stacks(a,b);
	return (FALSE);
}

int	rb(t_bi_list *nil)
{
	t_bi_list	*first;
	t_bi_list	*second;
	t_bi_list	*bottom;

	if (nil->next->next == nil)//スタックが空か１つだったらエラー
		return (TRUE);
	write(STDOUT_FILENO, RED, ft_strlen(RED));
	write(STDOUT_FILENO, "__[rb]__\n", 9);
	write(STDOUT_FILENO, END, ft_strlen(END));
	first = nil->next;
	second = nil->next->next;
	bottom = nil->prev;
	nil->next = second;
	second->prev = nil;
	nil->prev = first;
	first->next = nil;
	first->prev = bottom;
	bottom->next = first;
	command_num++;
	show_stack(nil);
	return (FALSE);
}

int	rrb(t_bi_list *nil)
{
	t_bi_list	*bottom;
	t_bi_list	*first;
	t_bi_list	*second;

	if (nil->next->next == nil)//スタックが空か１つだったらエラー
		return (TRUE);
	write(STDOUT_FILENO, RED, ft_strlen(RED));
	write(STDOUT_FILENO, "__[rrb]__\n", 10);
	write(STDOUT_FILENO, END, ft_strlen(END));
	bottom = nil->prev;
	first = nil->next;
	second = nil->prev->prev;
	nil->prev = second;
	second->next = nil;
	bottom->prev = nil;
	bottom->next = first;
	nil->next = bottom;
	bottom->next = first;
	first->prev = bottom;
	command_num++;
	return (FALSE);
}