#include "libft.h"

static long	ans_len(long n)
{
	long	sign;
	long	len;

	sign = 0;
	len = 1;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len + sign);
}

static char	*putans(char *str, long n, long len)
{
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[len] = '0' + (n % 10);
		n /= 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	*ans;
	long	len;

	n = (long)n;
	len = ans_len(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	ans = putans(str, n, len);
	return (ans);
}
