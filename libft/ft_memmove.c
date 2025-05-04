#include "libft.h"

void	*ft_memmove(void *dst, const void *src, unsigned long n)
{
	if (!dst && !src)
		return (0);
	if (!n)
		return (dst);
	if (src < dst)
	{
		while (n--)
			((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
