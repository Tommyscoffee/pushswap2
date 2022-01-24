#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	if (!s1 || !s2)//引数が存在しなかったらエラー処理
	{
		return (1);
	}
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	return (i);
}

long	ft_atol(const char *str)
{
	int			i;
	int			sign;
	long long	ans;

	sign = 1;
	ans = 0;
	i = ft_isspace(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		ans = ans * 10 + str[i] - '0';
		if (ans > LLONG_MAX && sign == 1)
			return (-1);
		if (ans - 1 > LLONG_MAX && sign == -1)
			return (0);
		i++;
	}
	return ((long)ans * sign);
}

int	main()
{
	char *num = "123";
	int		dig;

	dig = atol(num);	

	printf("%d\n",dig);
	system("leaks a.out");
	return (0);
}