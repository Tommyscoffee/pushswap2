#include "libft.h"
#define DIGITS "0123456789"

int	ft_isdigit(int c)
{
	int	i;

	i = 0;
	while (i < 10)
		if (c == DIGITS[i++])
			return (1);
	return (0);
}
