#include <stdio.h>
#include <stdlib.h>

struct s_node{
	int	data;
	struct s_node *next;
	struct s_node *first;
};

struct s_node *make_list()
{
	struct s_node *first;
	first = NULL;
	struct s_node **p = &first;
	int data;
	int i = 0;
	while (i++ < 5)
	{
		scanf("%d\n",&data);
		struct s_node *node = malloc(sizeof(struct s_node) * 1);
		if (node){
			node->data = data;
			node->next = NULL;
			*p = node;
			p = &node->next;
		}
		else
			break;
	}
	return (first);
};

void	delete_list(struct s_node *first)
{
	while (first)
	{
		struct s_node *next = first->next;
		free(first);
		first = next;
	}
}
void	display(struct s_node *p)
{
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}
int	list_delete_negatives(struct s_node **p)
{
	while (*p)
	{
	if ((*p)->data < 0)
	{
		struct s_node *next = (*p)->next;
		free(*p);
		(*p) = next;
	}
	else
		p = (*p)->next;
	}
}


int main()
{
	struct s_node *first = make_list();
	delete_list(first);
	return (0);
}