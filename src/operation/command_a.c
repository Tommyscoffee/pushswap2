/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:00:36 by akihito           #+#    #+#             */
/*   Updated: 2022/01/23 14:21:55 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	sa(t_bi_list *a)
{
	t_bi_list	*first;
	t_bi_list	*second;
	t_bi_list	*third;

	if (a->next->next == a)
	{
		write(1, "no\n", 3);
		return (TRUE);
	}
	write(STDOUT_FILENO, RED, ft_strlen(RED));
	write(STDOUT_FILENO, "__[sa]__\n", 9);
	write(STDOUT_FILENO, END, ft_strlen(END));
	first = a->next;
	second = a->next->next;
	third = a->next->next->next;

	a->next = second;
	second->next = first;
	first->next = third;
	third->prev = first;
	first->prev = second;
	second->prev = a;
	return (0);
}

int	pa(t_bi_list *a, t_bi_list *b)
{
	t_bi_list	*first_a;
	t_bi_list	*first_b;
	t_bi_list	*second_b;

	if (b->next->value == -1)
		return (TRUE);
	write(STDOUT_FILENO, RED, ft_strlen(RED));
	write(STDOUT_FILENO, "__[pa]__\n", 9);
	write(STDOUT_FILENO, END, ft_strlen(END));
	a->size_now++;
	b->size_now--;
	first_a = a->next;
	first_b = b->next;
	second_b = b->next->next;
	b->next = second_b;
	second_b->prev = b;
	a->next = first_b;
	first_b->next = first_a;
	first_a->prev = first_b;
	first_b->prev = a;
	print_stacks(a, b);
	return (FALSE);
}

int	ra(t_bi_list *nil)
{
	t_bi_list	*first;
	t_bi_list	*second;
	t_bi_list	*bottom;

	if (nil->next->next->value == -1)//スタックが空か１つだったらエラー
		return (TRUE);
	write(STDOUT_FILENO, RED, ft_strlen(RED));
	write(STDOUT_FILENO, "__[ra]__\n", 9);
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
	show_stack(nil);
	return (FALSE);
}

int	rra(t_bi_list *nil)
{
	t_bi_list	*bottom;
	t_bi_list	*first;
	t_bi_list	*second;

	if (nil->next->next->value == -1)//スタックが空か１つだったらエラー
		return (TRUE);
	write(STDOUT_FILENO, RED, ft_strlen(RED));
	write(STDOUT_FILENO, "__[raa]__\n", 10);
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
	return (FALSE);
}