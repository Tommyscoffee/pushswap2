#include <stdio.h>

void	sort_over6(t_dlist *a, t_dlist *b, t_ps *ps)
{
	long	size;

	half_set(a, b, ps);
	while (ps->awant != ps->size)
	{
		b_settle_top(a, b, ps);

		while ((size = dlist_size(b) > SORTSIZE))
			b_quick_sort(a, b, ps, size);
		if (size)
			allsort(a, b, ps, size);
		
		while ((size = search_a_size(a, ps)) && size <= SORTSIZE)
			allsort(a, b, ps, size);
		if (size)
			a_quick_sort(a, b, ps, size);
	}
}
