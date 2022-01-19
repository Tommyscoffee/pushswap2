/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_both.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:25:18 by akihito           #+#    #+#             */
/*   Updated: 2022/01/19 12:33:36 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"
int ss(t_bi_list *a, t_bi_list *b)
{
	int		exec;

	write(1, "[ss]\n", 5);
	exec = 0;
	exec = sa(a);
	exec = sb(b);
	if (exec != 0)
		return (TRUE);
	else
		return (FALSE);
}

int	rr(t_bi_list *a, t_bi_list *b)
{
	int		exec;

	exec = 0;
	write(1, "[rr]\n", 5);
	exec = ra(a);
	exec = rb(b);
	if (exec == 0)
		return (TRUE);
	else
		return (FALSE);
}