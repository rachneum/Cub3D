#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = (long) n;
	if (num < 0)
	{
		num *= -1;
		ft_putchar_fd('-', fd);
	}
	if (num > 9)
		ft_putnbr_fd((int)(num / 10), fd);
	ft_putchar_fd(num % 10 + '0', fd);
	return ;
}
