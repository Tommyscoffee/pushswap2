/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akihito <akihito@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:34:21 by akihito           #+#    #+#             */
/*   Updated: 2022/01/15 17:55:44 by akihito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# include <stdlib.h>
# include "../libft/libft.h"
# define YELLOW "\x1b[33m"
# define END		"\x1b[m"
# define STACK_A "stack[0]"
# define STACK_B "stack[1]"
# define TRUE	1
# define FALSE	0

# include <stdio.h>
typedef struct s_info
{
	int	stack_size;
}		t_info;

typedef struct s_bi_list {
	int					value;
	struct s_bi_list	*next;
	struct s_bi_list	*prev;
	// int					rank;
	int					stack_size;
	t_info				*info;
}		t_bi_list;

void	rotate(t_bi_list **lst);
int		sa(t_bi_list *nil);
int		sb(t_bi_list *nil);
int		ra(t_bi_list *nil);
int		rb(t_bi_list *nil);
int		rra(t_bi_list *nil);
int		rrb(t_bi_list *nil);
int		pa(t_bi_list *a, t_bi_list *b);
int		pb(t_bi_list *a, t_bi_list *b);
void	show_list(t_bi_list *nil);
int		rr(t_bi_list *a, t_bi_list *b);
int		ss(t_bi_list *a, t_bi_list *b);
//debug
int	get_digits(int	nbr);
int	get_max_digits(t_bi_list *nil);
int	print_stacks(t_bi_list *nil_a, t_bi_list *nil_b);
# endif