#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, unsigned long n)
{
	if (n == 0)
		return (0);
	while (*s1 && (*s1 == *s2) && n--)
	{
		if (n == 0)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
