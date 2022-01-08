#include "libft.h"

static int	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i ++;
	}
	return (words);
}

static int	words_len(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void	ft_free(char ***ans)
{
	size_t	i;

	i = 0;
	while ((*ans)[i] != NULL)
	{
		free((*ans)[i]);
		(*ans)[i] = NULL;
		i++;
	}
	free(*ans);
	*ans = NULL;
}

static char	**make_str(char const *s, int ans_count, char c, char **ans)
{
	int		i;
	size_t	j;
	size_t	len;

	i = -1;
	while (++i < ans_count)
	{
		while (*s == c)
			s++;
		len = words_len(s, c);
		ans[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!ans[i])
		{
			ft_free(&ans);
			return (NULL);
		}
		j = 0;
		while (j < len)
			ans[i][j++] = *s++;
		ans[i][j] = '\0';
	}
	ans[i] = NULL;
	return (ans);
}

char	**ft_split(char const *s, char c)
{
	char		**ans;
	size_t		ans_count;

	if (!s)
		return (NULL);
	ans_count = count_words(s, c);
	ans = (char **)malloc(sizeof(char *) * (ans_count + 1));
	if (!ans)
		return (NULL);
	ans = make_str(s, ans_count, c, ans);
	return (ans);
}
