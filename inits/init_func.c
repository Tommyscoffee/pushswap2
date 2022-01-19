/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:58:20 by akihito           #+#    #+#             */
/*   Updated: 2022/01/17 23:23:00 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	init_nil(t_bi_list *nil)
{
	nil->next = nil;
	nil->prev = nil;
	nil->value = -1;
	nil->rank = 0;
	return ;
}

void	asort(size_t *a, int idx){
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < idx)
	{
		j = i + 1;
		while (j < idx)
		{
			tmp = 0;
			if (a[i] > a[j])
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return ;
}

int	init_rank(t_bi_list *nil, size_t *sorted)
{
	t_bi_list	*p;
	size_t		i;
	size_t		j;

	p = nil->next;
	i = 0;
	j = 0;
	while (p != nil)
	{
		i = 0;
		while (i < nil->stack_size)
		{
			if (p->value == sorted[i])
			{
				p->rank = i + 1;
				break;
			}
			i++;
		}
		p = p->next;
	}
	return (0);

}

int	init_array(t_bi_list *nil_a)
{
	t_bi_list	*p;
	size_t		array[nil_a->stack_size];
	size_t		i;

	i = 0;
	p = nil_a->next;
	while (p != nil_a)
	{
		array[i++] = p->value;
		p = p->next;
	}
	asort(array, nil_a->stack_size);
	if (init_rank(nil_a, array))
		return (TRUE);
	i = 0;
	while (i < nil_a->stack_size)
	{
		printf("array = %zu\n",array[i]);
		i++;
	}
	return (0);
	
}

int	init_stack(int argc, char **argv, t_bi_list *nil)
{
	size_t		i;
	size_t		j;
	t_bi_list	*node;
	t_bi_list	*p;
	long		value;//これをsize_tにすると必ず「引数が範囲外」となる

	p = nil;
	i = 1;
	j = 1;
	nil->info = (t_info *)malloc(sizeof(t_info));
	if (!nil->info)
	{
		printf("malloc error\n");
		exit(1);
	}
	nil->info->stack_size = argc;
	while (i < argc)
	{
		check_alpha(argv[i]);
		value = ft_atol(argv[i]);
		if (value > 2147483647 || value < -2147483648)//引数がintの範囲
		{
			printf("引数が範囲外です\n");
			exit (1);
		}
		if (add_list(value, nil))
		{
			printf("add_list error\n");
			exit (1);
		}
		i++;
		
	}
	return (0);
}