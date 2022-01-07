#include <stdio.h>
#include <stdlib.h>
// https://www.youtube.com/watch?v=b2hcyLQHQxs
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
	int	list[] = {1,2,3,4,5,6};
	int i = 0;
	while (i <= 5)
	{
		data = list[i];
		struct s_node *node = malloc(sizeof(struct s_node) * 1);
		if (node){
			node->data = data;
			node->next = NULL;
			*p = node;
			p = &node->next;
		}
		else
			break;
		i++;
	}
	return (first);
};

void	delete_list(struct s_node *p)
{
	while (p)
	{
		struct s_node *next = p->next;
		free(p);
		p = next;
	}
}
void	display(struct s_node *p)
{
	// while (p->next != NULL)
	// {
	// 	printf("%d\n", p->data);
	// 	p = p->next;
	// }
	while (p)
	{
		printf("%d\n",p->data);
		p = p->next;
	}
	// printf("%d\n", p->data);
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
			p = &((*p)->next);
	}
	return (0);
}


int main()
{
	struct s_node *first = make_list();
	list_delete_negatives(&first);
	display(first);
	delete_list(first);
	return (0);
}