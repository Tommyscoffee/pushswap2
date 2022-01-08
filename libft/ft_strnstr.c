#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needles, size_t len)
{
	size_t	haystack_len;
	size_t	needle_len;
	size_t	i;
	char	*hay_cpy;
	char	*haystack_chr;

	haystack_chr = (char *)haystack;
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needles);
	if (*needles == 0)
		return (haystack_chr);
	if (len < haystack_len)
		haystack_len = len;
	i = 0;
	hay_cpy = (char *)haystack;
	if (haystack_len < needle_len)
		return (NULL);
	while (*(hay_cpy + i) != '\0' && i < haystack_len - needle_len + 1)
	{
		if (*(hay_cpy + i) == *needles)
			if (ft_strncmp(hay_cpy + i, needles, needle_len) == 0)
				return (hay_cpy + i);
		i += 1;
	}
	return (NULL);
}
