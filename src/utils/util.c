/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:46:28 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/19 20:46:42 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

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