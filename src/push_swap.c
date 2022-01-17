/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:58:29 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/17 19:01:15 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "../libft/libft.h"
#include "../includes/pushswap.h"
#define YELLOW "\x1b[33m"
#define END		"\x1b[m"
#define STACK_A "stack[0]"
#define STACK_B "stack[1]"
#define TRUE	1
#define FALSE	0

size_t	count_stack(int argc, char **argv)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = 0;
	i = 1;
	while (i < (size_t)argc)
	{
		j = 0;
		while (argv[i][j])
		{
			// printf("argv[%zu][%zu] = %c\n", i, j, argv[i][j]);
			if ((!j || argv[i][j - 1] == ' ') && argv[i][j] != ' ')
			{
				size++;// " 4  5 6"
				// printf("size++ されました。argv[%zu][%zu] = %c\n",i,j,argv[i][j]);
			}
			j++;
		}
		printf("=============count per argc: argc = %zu, size = %zu\n\n",i,size);
		i++;
	}
	return (size);
}

int	is_duplicated(t_bi_list *nil, int elm)
{
	int	i;
	t_bi_list	*p;

	p = nil->next;
	i = 0;
	while (p != nil)
	{
		if (p->value == elm)
			return (TRUE);
		p = p->next;
	}
	return (FALSE);
}

int	add_list(int value, t_bi_list *nil)
{
	t_bi_list	*node;
	t_bi_list	*prev;

	if (is_duplicated(nil, value))
	{
		printf("ダブってます: %d\n", value);
		exit (1);
	}
	prev = nil->prev;
	node = (t_bi_list *)malloc(sizeof(t_bi_list));
	if (!node)
	{
		printf("malloc error\n");
		exit(1);
	}
	node->value = value;
	nil->prev = node;
	prev->next = node;
	node->next = nil;
	node->prev = prev;
	return (0);
}

int	check_alpha(char *str)
{
	size_t	j;

	j = 0;
	while (str[j] != '\0')
	{
		if (!ft_isdigit((int)str[j]))
		{
			if (str[j] == '-' && ft_isdigit((int)str[j + 1]))//引数が--1の時はアルファベットと認識してエラーを吐く
				j++;
			else
			{
				printf("アルファベット エラー\n");
				exit(1);
			}
		}
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_bi_list	*nil_a;
	t_bi_list	*nil_b;

	printf("t_bi_list byte = %lu\n", sizeof(t_bi_list));
	nil_a = (t_bi_list *)malloc(sizeof(t_bi_list));
	nil_b = (t_bi_list *)malloc(sizeof(t_bi_list));
	init_nil(nil_a);
	init_nil(nil_b);
	nil_a->stack_size = argc - 1;
	init_stack(argc, argv, nil_a);//スタックAに引数を入れていく
	init_array(nil_a);
	// print_stacks(nil_a, nil_b);
	// printf("==\n");
	operation_stack(argc, nil_a, nil_b);
	// rra(nil_a);
	print_stacks(nil_a, nil_b);
	printf("nil_rank = %d\n",nil_a->rank);
	printf("first_rank = %d\n",nil_a->next->rank);
	// print_stacks(nil_a, nil_b);
	ft_free(nil_a);
	free(nil_b);
	// system("leaks a.out");
	return (0);
}
