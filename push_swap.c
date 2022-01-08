/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:58:29 by atomizaw          #+#    #+#             */
/*   Updated: 2022/01/08 22:31:23 by atomizaw         ###   ########.fr       */
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

int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	return (i);
}

int	ft_atoi_num(const char *str)
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
		if (ans > 2147483647 && sign == 1)
			return (-1);
		if (ans - 1 > 2147483647 && sign == -1)
			return (-1);
		i++;
	}
	if (!(str[i] <= '9' || str[i] >= '0'))//ここで、atoiに機能を追加して、数字以外の引数がいたらエラーにする
//!のなかの||は&&の意味
		return (-1);
	return ((int)ans * sign);
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

int	is_duplicated(t_info *stack, int elm)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i++] == elm)
			return (1);
	}
	return (0);
}

int	put_el_in_stack(char *cmd_arg, t_info *stack, size_t *stack_num)
{
	int		num;
	char	*str;
//ここでは、splitで実装したらいいが、二次元配列の二次元をどのくらいmallocすればいいかわからないからやめた。最大値ですればいいが、無駄
	while (*cmd_arg)
	{
		while (*cmd_arg && *cmd_arg == ' ')//数値が出てくるまでアドレスを進める
			cmd_arg++;
		if (!*cmd_arg)
			break ;
		str = ft_slice_str(cmd_arg, ' ');//
		printf("str = %s  ",str);
		num = ft_atoi_num(str);//普通のatoiだと、アルファベットは全て0になるので、他に0かアルファベットがあれば重複してるというエラーになる
		if (num < 0)
		{
			printf("num = %d\n", num);
			printf("atoiエラー\n");
			free(str);
			exit(1);
		}
		free(str);
		if (is_duplicated(stack, num))
		{
			printf("重複してるよ\n");
			exit(1);
		}
		stack->array[(*stack_num)++] = num;//ここで呼び出し元のjもインクリメントされている
		printf("num = %d\n", num);
		stack->size++;
		while (*cmd_arg && *cmd_arg != ' ')
			cmd_arg++;
	}
	return (0);
}

int	make_stack(int argc, char **argv, t_info *stack)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 1;
	j = 0;
	while (i < (size_t)argc)
	{
		ptr = argv[i];
		if (put_el_in_stack(ptr, stack, &j))
			return (1);
		i++;
	}
	return (0);
}

int	init_stack(int argc, char **argv, t_bi_list *sentinel_a)
{
	size_t	stack_size;
	size_t	i;
	t_bi_list	*node;
	t_bi_list	*p;

	p = sentinel_a;
	i = 0;

	while (i < argc)
	{
		node = (t_bi_list *)malloc(sizeof(t_bi_list));
		if(!node)
		{
			pritnf("malloc error\n");
			exit(1);
		}
		node->value = argv[i];
		p->next = node;
		sentinel_a->prev = node;
		node->next = sentinel_a;
		node->prev = p;
		p = p->next;
	}
	return (0);
}

int	get_digits(int	nbr)
{
	long	nnbr;
	int		size;

	nnbr = nbr;
	size = 0;
	if (nnbr < 0)
	{
		size++;
		nnbr *= -1;
	}
	if (nnbr != 0)
	{
		if (nnbr / 10 > 0)
		{
			size += get_digits(nnbr / 10);
			// printf("size = %zu\n",size);
		}
		return (++size);
	}
	if (nnbr == 0)
		size++;
	return (size);
}

int	get_max_digits(t_info *stack)
{
	int		size;
	size_t	i;

	if (!stack->size)
		size = 1;
	else
		size = get_digits(stack->array[0]);
	i = 1;
	while (i < stack->size)
	{
		if (size < get_digits(stack->array[i]))
			size = get_digits(stack->array[i]);
		i++;
	}
	return (size);
}

int	print_stacks(t_info **stack)
{
	int	max_size;//-vで表示する行数（＝引数の数）
	int	max_nbr[2];//それぞれのスタックで一番大きい桁数（＝横幅にする）
	int	line_len[2];//各行の要素の桁数
	int	i;
	int	j;

	i = 0;
	j = 0;
	max_size = stack[0]->limit;//スタックの最大要素数
	printf("max_size %d\n", max_size);
	write(STDOUT_FILENO, YELLOW, ft_strlen(YELLOW));
	write(STDOUT_FILENO, "stacks\n", 7);
	write(STDOUT_FILENO, END, ft_strlen(END));
	max_nbr[0] = get_max_digits(stack[0]);//最大桁数を検出する
	max_nbr[1] = get_max_digits(stack[1]);
	printf("max_nbr[0] %d\n", max_nbr[0]);
	printf("max_nbr[1] %d\n", max_nbr[1]);
	while (i < max_size)
	{
		char	*space[2];//要素のまえのスペースを格納する配列
		size_t		space_len[2];//スペースの数を格納する配列
		printf("-----------\n");
		while (j < 2)
		{
			line_len[j] = get_digits(stack[j]->array[i]);
			printf("j = %d:array[0] = %d\n",j, stack[j]->array[0]);
			space_len[j] = max_nbr[j] - line_len[j];
			space[j] = (char *)malloc(sizeof(char) * (space_len[j] + 1));
			if (!space[j])
			{
				exit(1);
			}
			ft_memset((void *)space[j], ' ', space_len[j]);//spaceの文字を入れている。
			space[j][space_len[j]] = '\0';
			write(1, space[j], space_len[j]);
			ft_putnbr_fd(stack[j]->array[i], 1);
			j++;
		}
		ft_putchar_fd('\n', 1);
		free(space[0]);
		free(space[1]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	t_stack		stack;
	t_bi_list	*sentinel_a;
	t_bi_list	*sentinel_b;

	init_sentinel(sentinel_a);
	init_sentinel(sentinel_b);
	if (!stack.stack)
	{
		printf("----\n");
		exit(1);
	}
	i = 0;
	if (!ft_strcmp(argv[1], "-v") && argc <= 2)
	{
		printf("-vだけど、引数ないよ\n");
		return (1);
	}
	stack.debug = 0;
	if (!ft_strcmp(argv[1], "-v"))
	{
		stack.debug = 1;
		printf("===================debug\n");
		if ((argc - 1, &argv[1], &stack.stack))
			return (1);
	}
	else if (ft_strcmp(argv[1], "-v") && argc <= 1)
	{
		printf("-vないし引数もないよ\n");
		return (1);
	}
	else if (init_stack(argc, argv, sentinel_a))
	{
		write(1, "Error3\n", 7);
		return (1);
	}
	if (stack.debug)
		print_stacks(&stack.stack);
	
	// printf("stack_size = %d\n", stack.stack_a.size);
	// while (i < stack.stack_a.size)
	// {
	// 	printf("%d\n", stack.stack_a.array[i]);
	// 	i++;
	// }
	return (0);
}
