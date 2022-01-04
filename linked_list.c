#include <stdio.h>

struct node{
	int			data;
	struct node *next;
};

void	display(const struct node *p)
{
	while (p != NULL)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

int main()
{
	struct node node4 = {4, NULL};
	struct node node3 = {3, &node4};
	struct node node2 = {2, &node3};
	struct node node1 = {1, &node2};
	struct node *head = &node1;

	struct node **p = &head;
	struct node node5 = {5};
	while (*p != NULL)
	{
		// printf("%d\n",(*p)->data);
		// if ((*p)->data == 2)
		// {
		// 	printf("===\n");
		// 	*p = &node5;
			 
		// }
		if ((*p)->data == 2)
		{
			printf("===\n");
			node5.next = *p;
			*p = &node5;
			break;//breakがないとwhiileが止まってしまう。
		}
		
		p = &(*p)->next;
	}
	display(head);
}