#include "libft.h"

int	o_size(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned long	j;
	unsigned long	ogsize;
	unsigned long	k;

	j = 0;
	k = 0;
	if (!dest && size == 0)
		return (0);
	ogsize = o_size(dest);
	while (src[k])
		k++;
	if (!(size <= 0))
	{
		while ((ogsize + j) < size - 1 && src[j])
		{
			dest[ogsize + j] = src[j];
			j++;
		}
	}
	dest[ogsize + j] = '\0';
	if (ogsize > size)
		return (k + size);
	else
		return (k + ogsize);
}
