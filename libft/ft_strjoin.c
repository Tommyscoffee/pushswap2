#include "libft.h"
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*ans;

	i = 0;
	j = 0;
	ans = NULL;
	if (!s1 || !s2)
		return (NULL);
	ans = (char *) malloc (ft_strlen (s1) + ft_strlen (s2) + 1);
	if (ans == 0 || s1 == NULL || s2 == NULL)
		return (NULL);
	while (s1[i] != 0)
	{
		ans[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		ans[i + j] = s2[j];
		j++;
	}
	ans[i + j] = '\0';
	return (ans);
}
