/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:17:15 by akihito           #+#    #+#             */
/*   Updated: 2022/01/17 17:15:58 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	if (!s1 || !s2)//引数が存在しなかったらエラー処理
	{
		return (1);
	}
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_free(t_bi_list *nil)
{
	t_bi_list	*p;
	t_bi_list	*tmp;

	if (!nil->info)
		free(nil->info);
	p = nil->next;
	while (p != nil)
	{
		tmp = p->next;
		free(p);
		p = tmp;
	}
	free(nil);
	return ;
}

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