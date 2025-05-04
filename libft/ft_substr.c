#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;
	size_t	l;

	if (!s)
		return (0);
	l = ft_strlen(s);
	i = 0;
	if (len > l)
		len = l;
	if (start + len > l)
		len = l - start;
	if (start > l)
		len = 0;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	while (i < len && (s[start + i] != '\0'))
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
