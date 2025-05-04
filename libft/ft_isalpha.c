#include "libft.h"

int	ft_isalpha(int ch)
{
	if ((ch > 64 && ch < 91) || (ch > 96 && ch < 123))
		return (1);
	else
		return (0);
}
