#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	ssize_t	idx;
	ssize_t	end_idx;
	ssize_t	len;

	if (!s1 || !set)
		return (NULL);
	idx = 0;
	end_idx = ft_strlen(s1) - 1;
	while (s1[idx] != '\0' && ft_strchr(set, s1[idx]))
		idx++;
	while (!(end_idx < idx) && ft_strchr(set, s1[end_idx]))
		end_idx--;
	len = end_idx - idx + 1;
	if (s1[idx] == '\0')
		return (ft_strdup(""));
	return (ft_substr(s1, idx, len));
}
