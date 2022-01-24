/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:32:18 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/24 17:41:08 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	arg_4(t_bi_list *nil_a, t_bi_list *nil_b)
{
	t_bi_list	*p;
	int			i;

	i = 0;
	printf("arg_4===============\n");
	p = nil_a->next;
	while (i < 4)
	{
		if (nil_a->next->rank == 1)
			pb(nil_a, nil_b);
		ra(nil_a);
		i++;
	}
	arg_3(nil_a);
	pa(nil_a, nil_b);
	return (0);
}
