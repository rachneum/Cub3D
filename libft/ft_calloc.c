#include "libft.h"

void	*ft_calloc(unsigned long count, unsigned long size)
{
	void	*ptr;

	ptr = NULL;
	if (count * size > 2147483647)
		return (0);
	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}
