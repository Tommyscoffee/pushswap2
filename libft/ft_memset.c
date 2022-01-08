#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*s_chr_p;

	i = 0;
	s_chr_p = (char *)b;
	while (i < len)
	{
		*(s_chr_p + i) = (char)c;
		i++;
	}
	return (b);
}
