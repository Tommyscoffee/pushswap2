#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ans;

	if (!s)
		return (NULL);
	i = 0;
	ans = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ans)
		return (0);
	while (s[i])
	{
		ans[i] = f(i, s[i]);
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
