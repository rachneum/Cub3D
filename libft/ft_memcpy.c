#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, unsigned long n)
{
	unsigned long	i;
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (0);
	if (!n)
		return (dst);
	i = 0;
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
