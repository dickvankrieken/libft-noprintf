#include "libft.h"

static void	convert_uint(unsigned int n, int fd)
{
	if (n >= 10)
		convert_uint(n / 10, fd);
	ft_putchar_fd((char)(n % 10 + '0'), fd);
	return ;
}

void		ft_putuint_fd(unsigned int n, int fd)
{
	convert_uint(n, fd);
	return ;
}
