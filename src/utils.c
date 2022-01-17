/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:17:15 by akihito           #+#    #+#             */
/*   Updated: 2022/01/16 00:30:02 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	return (i);
}

long	ft_atol(const char *str)
{
	int			i;
	int			sign;
	long long	ans;

	sign = 1;
	ans = 0;
	i = ft_isspace(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		ans = ans * 10 + str[i] - '0';
		if (ans > LLONG_MAX && sign == 1)
			return (-1);
		if (ans - 1 > LLONG_MAX && sign == -1)
			return (0);
		i++;
	}
	return ((long)ans * sign);
}