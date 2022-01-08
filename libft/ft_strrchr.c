#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = NULL;
	while (1)
	{
		if (*s == (char)c)
			p = (char *)s;
		if (*s == '\0')
			break ;
		s++;
	}
	return (p);
}
