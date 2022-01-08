#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_chr;
	char	*src_chr;
	char	*limit_max;
	char	*limit_min;

	dst_chr = (char *)dst;
	src_chr = (char *)src;
	limit_max = src_chr + len;
	limit_min = src_chr;
	if (len != 0)
	{
		if (dst_chr < src_chr)
			while (src_chr != limit_max)
				*dst_chr++ = *src_chr++;
		dst_chr += len;
		src_chr += len;
		if (dst_chr > src_chr)
			while (src_chr != limit_min)
				*--dst_chr = *--src_chr;
	}
	return (dst);
}
