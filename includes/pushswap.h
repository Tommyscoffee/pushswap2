/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atomizaw <atomizaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:34:21 by akihito           #+#    #+#             */
/*   Updated: 2022/02/02 14:49:29 by atomizaw         ###   ########.fr       */
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

int	command_num;

typedef struct s_bi_list {
	int					value;
	struct s_bi_list	*next;
	struct s_bi_list	*prev;
	int					rank;
	int					stack_size;
	// t_info				*info;
	int 				which;
	int					*array;
	int					pivot;//クイックソートする基準（stack_sizeの中央値）
	int					status;
	int					size_now;
	int					sorted;
	int 				sorted_rank;//スタックAのそこにソートされているランクを格納
	int					awant;
	int					bmax;
}		t_bi_list;

int		until_b_sequence(t_bi_list *nil_a, t_bi_list *nil_b);
int		after_push_b(t_bi_list *nil_a, t_bi_list *nil_b);
void	after_half(t_bi_list *nil_a, t_bi_list *nil_b);
int		after_push_b(t_bi_list *nil_a, t_bi_list *nil_b);
int		estimate_stack_a_sorted(t_bi_list *nil_a);
int		make_after_size_a(t_bi_list *nil_a, t_bi_list *nil_b);
int		make_after_size_b(t_bi_list *nil_a, t_bi_list *nil_b);
int		make_pivot_b(t_bi_list *nil_a, t_bi_list *nil_b);
int		make_pivot_a(t_bi_list *nil_a, t_bi_list *nil_b);
int		push_half_a_2(t_bi_list *nil_a, t_bi_list *nil_b);
int		pb_same_status(t_bi_list *nil_a, t_bi_list *nil_b);
void	ft_sortdone(void);
void	sort_set_operation(t_bi_list *nil_a);
int		set_sorted_a(t_bi_list *nil_a, t_bi_list *nil_b);
int		push_half_b(t_bi_list *nil_a, t_bi_list *nil_b);
int		Qsort_b(t_bi_list *nil_a, t_bi_list *nil_b);
int		push_half_a(t_bi_list *nil_a, t_bi_list *nil_b);
int		bottom_order(t_bi_list *nil_a, t_bi_list *nil_b);
int		sort_top_3_a_first(t_bi_list *nil_a, t_bi_list *nil_b);
int		sort_top_3_a_second(t_bi_list *nil_a, t_bi_list *nil_b);
int		sort_top_3_a(t_bi_list *nil_a, t_bi_list *nil_b);
int		check_rest_a(t_bi_list *nil_a, t_bi_list *nil_b);
int		bottom_to_bottom(t_bi_list *nil_a, t_bi_list *nil_b);
int		push_half2(t_bi_list *nil_a, t_bi_list *nil_b);
int		arg_4(t_bi_list *nil_a, t_bi_list *nil_b);
void	sort_bottom_213(t_bi_list *nil_a, t_bi_list *nil_b);
void	sort_bottom_321(t_bi_list *nil_a, t_bi_list *nil_b);
void	sort_bottom_312(t_bi_list *nil_a, t_bi_list *nil_b);
void	sort_bottom_231(t_bi_list *nil_a, t_bi_list *nil_b);
void	sort_bottom_132(t_bi_list *nil_a, t_bi_list *nil_b);
void	sort_bottom_123(t_bi_list *nil_a, t_bi_list *nil_b);
int		bottom_order_second(t_bi_list *nil_a, t_bi_list *nil_b);
int		bottom_order_first(t_bi_list *nil_a, t_bi_list *nil_b);
int		check_bottom_3(t_bi_list *nil);
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