/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:46:28 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/22 16:18:20 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	is_sorted(t_bi_list *nil)
{
	t_bi_list	*p;
	int			i;

	i = 0;
	p = nil->next;//
	while (p->next != nil)
	{
		if (p->rank > p->next->rank)
		{//未ソートだったら1を返す
			return (1);
		}
		p = p->next;
		i++;
	}
	printf("nil->size_now = %d\n", nil->size_now);
	if (nil->size_now != nil->stack_size)
		return (1);
	return (0);
}