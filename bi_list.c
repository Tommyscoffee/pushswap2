#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// http://www3.nit.ac.jp/~tamura/algorithm/lesson08.html　番兵ノードの説明
// https://hiroyukichishiro.com/list-in-c-language/#i-4 
typedef struct s_bi_list {
	int					value;
	struct s_bi_list	*next;
	struct s_bi_list	*prev;
}		t_bi_list;

void	init_sentinel(t_bi_list *sentinel)
{
	sentinel->next = sentinel;
	sentinel->prev = sentinel;
	sentinel->value = 0;
	return ;
}
void	push_back_list(t_bi_list *sentinel, int value)
{
	t_bi_list	*node;
	t_bi_list	*p;

	p = sentinel;
	node = (t_bi_list *)malloc(sizeof(t_bi_list));
	if (!node)
	{
		printf("malloc error\n");
		exit(1);
	}
	while (p->next != sentinel)//リストの最後まで回してあげる
	{
		p = p->next;
	}
	p->next->prev = node;//番兵ノードのprevを新しく追加するノードにしている
	p->next = node;

	node->prev = p;
	node->value = value;
	node->next = sentinel;//追加するノードのnextは番兵ノードになる。
}
//
// t_bi_list	*sentinel_a;//番兵ノードとして宣言
// 	t_bi_list	*sentinel_b;//番兵ノードとして宣言
// 	int			i;

// 	init_sentinel(sentinel_a);
// 	init_sentinel(sentinel_b);
// 	i = 0;

// int	init_stack(int argc, char **argv, t_bi_list *sentinel_a)
// {
// 	size_t	stack_size;
// 	size_t	i;
// 	t_bi_list	*node;
// 	t_bi_list	*p;

// 	p = sentinel_a;
// 	i = 0;

// 	while (i < argc)
// 	{
// 		node = (t_bi_list *)malloc(sizeof(t_bi_list));
// 		if(!node)
// 		{
// 			pritnf("malloc error\n");
// 			exit(1);
// 		}
// 		node->value = argv[i];
// 		p->next = node;
// 		sentinel_a->prev = node;
// 		node->next = sentinel_a;
// 		node->prev = p;
// 		p = p->next;
// 	}

void	show_list(t_bi_list *sentinel)
{
	t_bi_list	*node;
	node = sentinel->next;
	while (node != sentinel)
	{
		printf("%d\n",node->value);
		node = node->next;
	}
	printf("sentinel\n");
}

int	insert_list(t_bi_list *sentinel, int value, size_t index)
{
	t_bi_list	*prev;//挿入するまえのノード
	t_bi_list	*node;
	int			i;

	i = 0;
	prev = sentinel;
	while (i < index)
	{
		prev = prev->next;
		if (prev == sentinel)
		{
			printf("Error: not found index\n");
			return (1);
		}
		i++;
	}
	node = (t_bi_list *)malloc(sizeof(t_bi_list));
	if (!node)
	{
		printf("malloc error\n");
		return (1);
	}
	node->prev = prev;
	node->next = prev->next;
	node->value = value;

	prev->next = node;
	node->next->prev = node;
	return (0);
}

int	main()
{
	t_bi_list	*sentinel_a;//番兵ノードとして宣言
	t_bi_list	*sentinel_b;//番兵ノードとして宣言
	init_sentinel(sentinel_a);//番兵ノードの作成
	push_back_list(sentinel_a, 1);
	push_back_list(sentinel_a, 2);
	push_back_list(sentinel_a, 3);
	push_back_list(sentinel_a, 4);
	insert_list(sentinel_a, 0, 0);
	show_list(sentinel_a);
	return (0);
}