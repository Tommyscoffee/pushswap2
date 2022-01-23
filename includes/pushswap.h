/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:34:21 by akihito           #+#    #+#             */
/*   Updated: 2022/01/23 01:29:06 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define YELLOW 	"\x1b[33m"
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define END		"\x1b[m"
# define STACK_A "stack[0]"
# define STACK_B "stack[1]"
# define TRUE	1
# define FALSE	0
# define A		0
# define B		1
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>
typedef struct s_info
{
	int	stack_size;
}		t_info;

typedef struct s_bi_list {
	int					value;
	struct s_bi_list	*next;
	struct s_bi_list	*prev;
	int					rank;
	int					stack_size;
	t_info				*info;
	int 				which;
	int					*array;
	int					pivot;//クイックソートする基準（stack_sizeの中央値）
	int					status;
	int					size_now;
}		t_bi_list;


int		is_a_want(t_bi_list *nil_a, t_bi_list *nil_b);
int		is_b_want(t_bi_list *nil_a, t_bi_list *nil_b);
int		show_stack(t_bi_list *nil);
int		push_half(t_bi_list *nil_a, t_bi_list *nil_b);
int		arg_3(t_bi_list *nil);
int		sort_3_b_second(t_bi_list *nil_b);
int	 	sort_3_b_first(t_bi_list *nil_b);
int		sort_3_a_first(t_bi_list *nil_a);
int		sort_3_a_second(t_bi_list *nil_a);
int		arg_5(t_bi_list *nil_a, t_bi_list *nil_b);
int		Qsort(t_bi_list *nil_a, t_bi_list *nil_b);
int		arg_6(t_bi_list *nil_a, t_bi_list *nil_b);
int		arg_3_to_6(int argc, t_bi_list *nil_a, t_bi_list *nil_b);
int		arg_2(t_bi_list *nil_b);
int		is_sorted(t_bi_list *nil);
int		arg_2_b(t_bi_list *nil_b);
int		is_sorted(t_bi_list *nil);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_free(t_bi_list *nil);
int		ft_isspace(const char *str);
long	ft_atol(const char *str);
int		add_list(int value, t_bi_list *nil);
int		check_alpha(char *str);
int		operation_stack(int argc, t_bi_list *nil_a, t_bi_list *nil_b);
int		ft_isspace(const char *str);
long	ft_atol(const char *str);
int		init_stack(int argc, char **argv, t_bi_list *nil);
void	init_nil(t_bi_list *nil);
int		init_array(t_bi_list *nil_a);
void	rotate(t_bi_list **lst);
int		sa(t_bi_list *nil);
int		sb(t_bi_list *nil);
int		ra(t_bi_list *nil);
int		rb(t_bi_list *nil);
int		rra(t_bi_list *nil);
int		rrb(t_bi_list *nil);
int		pa(t_bi_list *a, t_bi_list *b);
int		pb(t_bi_list *a, t_bi_list *b);
int		rr(t_bi_list *a, t_bi_list *b);
int		ss(t_bi_list *a, t_bi_list *b);

//debug
int	get_digits(int	nbr);
int	get_max_digits(t_bi_list *nil);
int	print_stacks(t_bi_list *nil_a, t_bi_list *nil_b);
#endif