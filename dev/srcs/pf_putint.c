#include "../libft/libft.h"

static int		ft_numberofchars(int n)
{
	int i;

	i = 0;
	while (n /= 10)
	{
		i++;
	}
	return (i);
}

void 			pf_putint(int n)
{
	char string[ft_numberofchars(n)];
	int i;

	i = ft_numberofchars(n) + 1;
	string[i] = '\0';
	i--;
	while (i >= 0)
	{
		string[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	ft_putstr_fd(string, 1);
}
