#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*cpy;

	len = ft_strlen(s1);
	cpy = malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (0);
	i = 0;
	while (i < len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = s1[i];
	return (cpy);
}
