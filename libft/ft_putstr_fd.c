#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	long	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
