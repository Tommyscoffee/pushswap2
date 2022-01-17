/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:58:29 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/17 13:07:04 by akihito          ###   ########.fr       */
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

char	*ft_slice_str(const char *cmd_arg, char point)
{
	char	*ans;
	int		i;
	int		j;

	i = 0;
	j = 0;
	// printf("cmd_arg = %s\n", cmd_arg);
	while (cmd_arg[i] && cmd_arg[i] != point)
		i++;
	ans = (char *)malloc(sizeof(char) * (i + 1));
	if (!ans)
	{
		printf("malloc失敗\n");
		exit(1);
	}
	i = 0;
	while (cmd_arg[i] && cmd_arg[i] != point)
	{
		ans[i] = cmd_arg[i];
		// printf("cmd_arg[%d] = %c\n",i , ans[i]);
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

int	is_duplicated(t_bi_list *nil, int elm)
{
	int	i;
	t_bi_list	*p;//

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
		printf("ダブってます: %d\n",value);
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


void	ft_free(t_bi_list *nil)
{
	t_bi_list	*p;
	t_bi_list	*tmp;

	if (nil->info)
		free(nil->info);
	p = nil->next;
	while (p != nil)
	{
		tmp = p->next;
		free(p);
		// printf("%d\n",p->value);
		p = tmp;
	}
	free(nil);
	return	;
}
int	main(int argc, char **argv)
{
	t_bi_list	*nil_a;
	t_bi_list	*nil_b;

	printf("t_bi_list byte = %lu\n",sizeof(t_bi_list));
	nil_a = (t_bi_list *)malloc(sizeof(t_bi_list));
	nil_b = (t_bi_list *)malloc(sizeof(t_bi_list));
	init_nil(nil_a);
	init_nil(nil_b);
	nil_a->stack_size = argc - 1;
	init_stack(argc, argv, nil_a);//スタックAに引数を入れていく
	init_array(nil_a);
	print_stacks(nil_a, nil_b);
	// operation_stack(argc, nil_a, nil_b);
	
	// rrb(nil_b);
	// print_stacks(nil_a, nil_b);
	// rrb(nil_b);
	// print_stacks(nil_a, nil_b);
	// rrb(nil_b);
	// print_stacks(nil_a, nil_b);
	// sa(nil_a);
	// print_stacks(nil_a, nil_b);
	// sb(nil_b);
	// print_stacks(nil_a, nil_b);
	// rr(nil_a,nil_b);
	// pb(nil_a, nil_b);
	// pb(nil_a, nil_b);
	// pb(nil_a, nil_b);
	// pb(nil_a, nil_b);
	// // print_stacks(nil_a, nil_b);
	// pa(nil_a, nil_b);
	// if (sa(nil_a))
	// {
	// 	printf("sa_error\n");
	// 	exit(1);
	// }
	// print_stacks(nil_a, nil_b);
	// printf("stack_size = %d\n",nil_a->stack_size);
	ft_free(nil_a);
	ft_free(nil_b);
	// system("leaks a.out");
	return (0);
}
