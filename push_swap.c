/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:58:29 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/12 17:29:54 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
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
	int	stack_size;
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
	int					rank;//番兵ノードはランク０
	t_info				*info;
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
	t_bi_list	*p;//

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
	prev = nil->prev;
	// while (prev->next != nil)
	// {
	// 	prev = prev->next;
	// 	nil->info->stack_size++;
	// }
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
				printf("アルファベット　エラー\n");
				exit(1);
			}
		}
		j++;
	}
	return (0);
}


int	init_stack(int argc, char **argv, t_bi_list *nil)
{
	size_t	i;
	size_t	j;
	t_bi_list	*node;
	t_bi_list	*p;
	long	value;//これをsize_tにすると必ず「引数が範囲外」となる
	p = nil;
	i = 1;
	j = 1;
	nil->info = (t_info *)malloc(sizeof(t_info));
	if (!nil->info)
	{
		printf("malloc error\n");
		exit(1);
	}
	nil->info->stack_size = -1;
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

int	sa(t_bi_list *nil, t_bi_list *high, t_bi_list *low)
{
	nil->next = low;
	nil->prev = high;
	low->next = high;
	low->prev = nil;
	high->next = nil;
	high->prev = low;
	return (0);
}

int	sb(t_bi_list *nil, t_bi_list *high, t_bi_list *low)
{
	nil->next = low;
	nil->prev = high;
	low->next = high;
	low->prev = nil;
	high->next = nil;
	high->prev = low;
	return (0);
}

void	rotate(t_bi_list **lst)
{
	if ((*lst)->next )
		*lst = (*lst)->next;
}

// int	ra(t_bi_list *nil)
// {
// 	nil->next = low;
// 	nil->prev = high;
// 	low->next = high;
// 	low->prev = nil;
// 	high->next = nil;
// 	high->prev = low;
// 	return (0);
// }




int	operation_stack(int argc, t_bi_list *nil_a, t_bi_list *nil_b)
{
	if (argc < 4)
	{
		if (argc == 2)
		{
			show_list(nil_a);
			show_list(nil_b);
		}
		if (argc == 3)
		{
			printf("argc = 3\n");
			if ( nil_a->next->value > nil_a->prev->value)
				sa(nil_a, nil_a->next, nil_a->prev);
			else
			{
				printf("何もしない\n");
			}
		}
		if (argc == 4)
		{
			printf("argc = 4\n");
			if (nil)

		}
	}
	return (0);
}

void	ft_free(t_bi_list *nil)
{
	t_bi_list	*p;
	t_bi_list	*tmp;

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

	nil_a = (t_bi_list *)malloc(sizeof(t_bi_list));
	// nil_b = (t_bi_list *)malloc(sizeof(t_bi_list));
	printf("nil_aのメモリサイズ %lu\n",sizeof(t_bi_list));
	init_nil(nil_a);
	
	init_stack(argc, argv, nil_a);//スタックAに引数を入れていく
	operation_stack(argc, nil_a, nil_b);
	show_list(nil_a);//スタックAを表示している。

	printf("stack_size = %d\n",nil_a->info->stack_size);
	ft_free(nil_a);
	// ft_free(nil_b);
	// system("leaks a.out");
	return (0);
}
