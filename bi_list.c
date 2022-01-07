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
	t_bi_list	*prev;
	t_bi_list	*node;
	int			i;

	i = 0;
	prev = sentinel;
	while (i < index)
	{
		prev = prev->next;
	}
}

int	main()
{
	t_bi_list	*sentinel;//番兵ノードとして宣言
	init_sentinel(sentinel);//番兵ノードの作成
	push_back_list(sentinel, 1);
	push_back_list(sentinel, 2);
	push_back_list(sentinel, 3);
	push_back_list(sentinel, 5);
	show_list(sentinel);
	return (0);
}