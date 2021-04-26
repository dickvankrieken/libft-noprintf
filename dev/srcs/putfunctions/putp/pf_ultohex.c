#include "../../../libft/libft.h"

static int		numberofchars(int n)
{
	int i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static char	*ft_convert(unsigned long num, int allchars)
{
	int		i;
	char	*a;

	i = allchars - 1;
	a = ft_calloc(allchars + 1, sizeof(char));
	if (!a)
		return (NULL);
	while (i >= 0)
	{
		a[i] = (num % 16) + '0';
		num /= 16;
		i--;
	}
	return (a);
}

char	*pf_ultohex(unsigned long n)
{
	int		allchars;

	allchars = numberofchars(n);
	return (ft_convert(n, allchars));
}
