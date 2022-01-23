/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:36:42 by akihito           #+#    #+#             */
/*   Updated: 2022/01/23 19:52:09 by atomizaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	show_stack(t_bi_list *nil)
{
	t_bi_list	*p;

	p = nil->next;
	while (p != nil)
	{
		printf("%d\t(%d)\n", p->value, p->rank);
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

int	get_max_digits(t_bi_list *nil)
{
	int			size;
	size_t		i;
	t_bi_list	*p;

	p = nil->next;
	if (nil->next == nil)//スタックが空か１つだったらエラー
		return (2);//nil->valueの-1分の桁数を返してあげる
	// size = get_digits(p->value);
	size = get_digits(p->value);
	i = 1;
	while (p != nil)
	{
		if (size < get_digits(p->value))
			size = get_digits(p->value);
		p = p->next;
	}
	return (size);
}

int	print_stacks(t_bi_list *nil_a, t_bi_list *nil_b)
{
	int			line_size;//-vで表示する行数（＝引数の数）
	int			max_digits[2];//それぞれのスタックで一番大きい桁数（＝横幅にする）
	int			line_len[2];//各行の要素の桁数
	int			i;
	t_bi_list	*p_a;
	t_bi_list	*p_b;

	p_a = nil_a->next;
	p_b = nil_b->next;
	i = 0;
	line_size = nil_a->stack_size;
	// printf("max_size %d\n", line_size);

	max_digits[0] = get_max_digits(nil_a);//最大桁数を検出する
	max_digits[1] = get_max_digits(nil_b);//最大桁数を検出する
	if (max_digits[0] < max_digits[1])
		max_digits[0] = max_digits[1];
	// ここでそれぞれのスタックの幅をmax_nbr[]にしてあげるて、型を作る
	// max_size:スタックの要素数, max_digits:スタックごとの最大桁　で空白をwriteする
	// max_digits - get_digits(array[i]) で空白を出力
	while (p_a != nil_a || p_b != nil_b)//各行を出力
	{
		char		*space[2];//要素のまえのスペースを格納する配列
		size_t		space_len[2];//スペースの数を格納する配列
		// 各行の要素の桁数を取得する
		if (p_a != nil_a)
			line_len[0] = get_digits(p_a->rank);
		else
			line_len[0] = 0;
		if (p_b != nil_b)
			line_len[1] = get_digits(p_b->rank);
		else
			line_len[1] = 0;
		space_len[0] = max_digits[0] - line_len[0];
		space_len[1] = max_digits[0] - line_len[1];
		space[0] = (char *)malloc(sizeof(char) * (space_len[0] + 1));
		if (!space[0])
		{
			exit(1);
		}
		space[1] = (char *)malloc(sizeof(char) * (space_len[1] + 1));
		if (!space[1])
			exit(1);
		// printf("line_len[0] = %d\n", line_len[0]);
		ft_memset((void *)space[0], ' ', space_len[0]);//spaceの文字を入れている。
		ft_memset((void *)space[1], ' ', space_len[1]);
		space[0][space_len[0]] = '\0';
		space[1][space_len[1]] = '\0';
		write(1, space[0], space_len[0]);
		if (p_a != nil_a)
		{
			ft_putnbr_fd(p_a->rank, 1);
			// ft_putnbr_fd(p_a->rank, 1);
			p_a = p_a->next;
		}
		write(1, " |", 2);
		write(1, space[1], space_len[1]);
		if (p_b != nil_b)
		{
			ft_putnbr_fd(p_b->rank, 1);
			// ft_putnbr_fd(p_b->rank, 1);
			p_b = p_b->next;
		}
		ft_putchar_fd('\n', 1);
		free(space[0]);
		free(space[1]);
		i++;
	}
	printf("==============\n");

	// print_numbers_stacks(max_size, max_digits, nil_a, nil_b);
	// printf_bottom_stack(max_digits);
	return (0);
}