#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		ans;

	i = 0;
	ans = 0;
	while (i < n && (*s1 != 0 || *s2 != 0))
	{
		ans = (unsigned char)*(s1) - (unsigned char)*(s2);
		if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0')
			return (ans);
		i++;
		s1 += 1;
		s2 += 1;
	}
	return (0);
}
