#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct LinkedList_tag{
	int						value;
	struct	LinkedList_tag	*next;
	struct	LinkedList_tag	*prev;
};
void	init_head()
{
	gHead.value = 0;
	gHead.next = &gHead;
	gHead.prev = &gHead;
}

int	main()
{
	init_head();

	while( 1 ){
		print_explain();

	}
}