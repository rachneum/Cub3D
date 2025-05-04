#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != '\n')
			j++;
		i++;
	}
	return (j);
}
