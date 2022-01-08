#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t		i;
	size_t		len;
	char		*ans;

	len = ft_strlen(src);
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (ans == 0)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		ans[i] = src[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
