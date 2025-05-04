#include "libft.h"

void	ft_bzero(void *s, unsigned long n)
{
	unsigned long	i;
	char			*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	return ;
}
