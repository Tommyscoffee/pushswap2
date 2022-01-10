/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:58:29 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/09 17:10:11 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

#define YELLOW "\x1b[33m"
#define END		"\x1b[m"
#define STACK_A "stack[0]"
#define STACK_B "stack[1]"
#define TRUE	1
#define FALSE	0

//これらはtkiriharさんのメモリ管理
// #include "libmem_mgt/mem_mgt.h"
// #include "libmem_mgt/replace_mem_mgt.h"
//参考サイト　https://hiroyukichishiro.com/list-in-c-language/#i-4
typedef struct s_info
{
	struct s_info	*next;
	struct s_info	*prev;
	int				value;
	int				size;
	int				limit;
	int				*array;
	char			**elm;
}		t_info;

typedef struct s_stack{
	// struct s_info	*stack;//stack[0]->array = 0;
	struct s_info	stack[2];//スタック領域に値が書き込まれる。
	// struct s_info	*stack;//この時点ではポインタだけで、この後はmallocして
	// struct s_info	stack_a;
	// struct s_info	stack_b;
	int				debug;
}		t_stack;

typedef struct s_bi_list {
	int					value;
	struct s_bi_list	*next;
	struct s_bi_list	*prev;
}		t_bi_list;

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
	t_bi_list	*p;

	p = (t_bi_list *)malloc(sizeof(t_bi_list));
	p = nil;
	i = 0;
	while (p->next != nil)
	{
		if (p->value == elm)
			return (1);
		p = p->next;
	}
	return (0);
}

int	add_list(int value, t_bi_list *nil)
{
	t_bi_list	*node;
	t_bi_list	*prev;

	if (is_duplicated(nil, value))
	{
		printf("ダブってます: %d\n",value);
		return (1);
	}
	prev = nil;
	while (prev->next != nil)
	{
		prev = prev->next;
	}
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
		if (!ft_isdigit((int)str[j++]))
		{
			printf("アルファベット\n");
			exit(1);
		}
	}
	return (0);
}


int	init_stack(int argc, char **argv, t_bi_list *nil)
{
	size_t	i;
	size_t	j;
	t_bi_list	*node;
	t_bi_list	*p;
	size_t	value;
	p = nil;
	i = 1;
	j = 1;

	while (i < argc)
	{
		check_alpha(argv[i]);
		value = ft_atoi(argv[i]);
		printf("%lu\n",value);
		if (value > INT_MAX || value < INT_MIN)
		{
			printf("引数が範囲外です\n");
			exit(1);
		}
		if (add_list(value, nil))
		{
			return (1);
		}
		i++;
		
	}
	return (0);
}

// void	init_nil(t_bi_list *nil)
// {
// 	nil->next = nil;
// 	nil->prev = nil;
// 	nil->value = 0;
// 	return ;
// }

void	show_list(t_bi_list *nil)
{
	t_bi_list	*node;
	node = nil->next;
	while (node != nil)
	{
		printf("%d\n",node->value);
		node = node->next;
	}
	printf("nil\n");
}

void	init_nil(t_bi_list *nil)
{
	nil->next = nil;
	nil->prev = nil;
	nil->value = 0;
	return ;
}
int	main(int argc, char **argv)
{
	t_bi_list	*nil_a;
	t_bi_list	*nil_b;

	nil_a = (t_bi_list *)malloc(sizeof(t_bi_list));
	nil_b = (t_bi_list *)malloc(sizeof(t_bi_list));
	init_nil(nil_a);
	
	// init_nil(nil_b);
	// if (!stack.stack)
	// {
	// 	printf("----\n");
	// 	exit(1);
	// }
	// i = 0;
	// if (!ft_strcmp(argv[1], "-v") && argc <= 2)
	// {
	// 	printf("-vだけど、引数ないよ\n");
	// 	return (1);
	// }
	// stack.debug = 0;
	// if (!ft_strcmp(argv[1], "-v"))
	// {
	// 	stack.debug = 1;
	// 	printf("===================debug\n");
	// 	if ((argc - 1, &argv[1], &stack.stack))
	// 		return (1);
	// }
	// else if (ft_strcmp(argv[1], "-v") && argc <= 1)
	// {
	// 	printf("-vないし引数もないよ\n");
	// 	return (1);
	// }
	init_stack(argc, argv, nil_a);
	// if (init_stack(argc, argv, nil_a))
	// {
	// 	free(nil_a);
	// 	return (1);
	// }
	show_list(nil_a);
	// if (stack.debug)
	// 	print_stacks(&stack.stack);
	
	// printf("stack_size = %d\n", stack.stack_a.size);
	// while (i < stack.stack_a.size)
	// {
	// 	printf("%d\n", stack.stack_a.array[i]);
	// 	i++;
	// }
	return (0);
}
