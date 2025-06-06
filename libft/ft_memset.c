#include "libft.h"

void	*ft_memset(void *b, int c, unsigned long len)
{
	unsigned long	i;
	unsigned char	*mem;

	mem = b;
	i = 0;
	while (i < len)
	{
		mem[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
