/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Qsort_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 21:58:06 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/23 22:12:53 by atomizaw         ###   ########.fr       */
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
	if (first < bottom && second < bottom)
		return (1);
	else if (first < bottom)
		return (2);
	else if (first > bottom)
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
	if (first > bottom && second < bottom)
	{
		if (first < bottom)
			return(4);
		else if (first > bottom)
			return (5);
		return (4);
	}
	else if (first < bottom)
		return (2);
	else if (first > bottom)
		return (3);
	printf("bottom_order_firstでエラーーーー\n");
	exit(1);
}
