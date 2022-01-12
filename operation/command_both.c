/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_both.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:25:18 by akihito           #+#    #+#             */
/*   Updated: 2022/01/12 21:33:02 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	rr(t_bi_list *a, t_bi_list *b)
{
	int		exec;

	exec = 0;
	exec += ra(a);
	exec += ra(b);
	return (exec);//
}