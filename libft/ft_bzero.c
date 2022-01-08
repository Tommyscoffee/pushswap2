#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s_chr_p;

	i = 0;
	s_chr_p = (char *)s;
	while (i < n)
	{
		*(s_chr_p + i) = 0;
		i++;
	}
}
