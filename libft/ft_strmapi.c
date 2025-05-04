#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	long	i;
	char	*str;

	i = 0;
	if (!s || !f)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (0);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
