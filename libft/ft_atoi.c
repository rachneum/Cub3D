#include "libft.h"

static int	spacer(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' '
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long int	i;
	long int	res;
	long int	minus;
	long int	previous;

	res = 0;
	minus = 1;
	i = spacer((char *)str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		previous = res;
		res = (res * 10) + (str[i] - 48);
		if (previous > res && minus == 1)
			return (-1);
		if (previous > res && minus == -1)
			return (0);
		i++;
	}
	return (res * minus);
}
