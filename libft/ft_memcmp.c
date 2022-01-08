#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int					ans;
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (n-- != 0)
	{
		ans = (int)(*(p1++) - *(p2++));
		if (ans != 0)
			return (ans);
	}
	return (0);
}
