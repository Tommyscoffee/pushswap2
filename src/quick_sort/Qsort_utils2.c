/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Qsort_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:58:06 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/24 14:15:02 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	bottom_order_first(t_bi_list *nil_b)
{
	int	bottom;
	int	second;
	int	first;

	bottom = nil_b->prev->rank;
	second = nil_b->prev->prev->rank;
	first = nil_b->prev->prev->prev->rank;
	if (second > bottom)
		return (1);
	else if (first < bottom)
		return (2);
	else if (second > bottom)
		return (3);
	printf("bottom_order_firstでエラーーーー\n");
	exit(1);
}

int	bottom_order_second(t_bi_list *nil_b)
{
	int	bottom;
	int	second;
	int	first;

	bottom = nil_b->prev->rank;
	second = nil_b->prev->prev->rank;
	first = nil_b->prev->prev->prev->rank;
	if (first < second && second < bottom)
	{
		if (first < bottom)
			return (4);
		else if (first < bottom)
			return (5);
		return (0);
	}
	if (first > bottom)
		return (6);
	else if (first < bottom)
		return (7);
	printf("bottom_order_firstでエラーーーー\n");
	exit(1);
}
