/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:46:28 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/27 23:25:00 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	is_sorted(t_bi_list *nil)
{
	t_bi_list	*p;
	int			i;

	i = 0;
	p = nil->next;//
	while (p->next != nil && nil_a->size_now == nil_a->stack_size)
	{
		if (p->rank > p->next->rank)
		{//未ソートだったら1を返す
			return (0);
		}
		p = p->next;
		i++;
	}
	printf("nil->size_now = %d\n", nil->size_now);
	if (nil->size_now != nil->stack_size)
		return (1);
	write(STDOUT_FILENO, GREEN, ft_strlen(GREEN));
	write(STDOUT_FILENO, "command_num =", 13);
	write(STDOUT_FILENO, ft_itoa(command_num), ft_strlen(ft_itoa(command_num)));
	write(STDOUT_FILENO, END, ft_strlen(END));
	printf("\n");
	exit(1);
	return (1);
}
