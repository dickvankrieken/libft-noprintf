#include "../../../includes/ft_printf.h"

static int		numberofchars(int n)
{
	int i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_convert(unsigned int num, int allchars)
{
	int		i;
	char	*a;

	i = allchars - 1;
	a = ft_calloc(allchars + 1, sizeof(char));
	if (!a)
		return (NULL);
	while (i >= 0)
	{
		a[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	return (a);
}

char	*ft_uitoa(unsigned int n)
{
	int		allchars;

	allchars = numberofchars(n);
	return (ft_convert(n, allchars));
}
