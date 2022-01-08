#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	idx;
	size_t	i;

	idx = (size_t)start;
	ans = malloc(len + 1);
	i = 0;
	if (!s)
		return (NULL);
	if (ans == 0)
		return (NULL);
	while (i < len)
	{
		if (idx <= ft_strlen(s))
			ans[i] = s[idx];
		idx++;
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
