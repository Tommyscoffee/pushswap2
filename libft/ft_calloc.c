#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	n;
	void	*ans;

	n = count * size;
	ans = malloc(n);
	if (ans == 0)
		return (NULL);
	 ft_bzero(ans, n);
	return (ans);
}
