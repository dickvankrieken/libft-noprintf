#include "libft.h"

int		numberofchars(int n)
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

char	*ft_convert(int isneg, int num, int allchars)
{
	int		i;
	char	*a;

	i = allchars - 1;
	a = ft_calloc(allchars + 1, sizeof(char));
	if (!a)
		return (NULL);
	if (isneg)
		num *= -1;
	while (i >= 0)
	{
		if (i == 0 && isneg)
		{
			a[i] = '-';
			i--;
		}
		else
		{
			a[i] = (num % 16) + '0';
			num /= 16;
			i--;
		}
	}
	return (a);
}

char	*pf_ultohex(int n)
{
	int		allchars;

	allchars = numberofchars(n);
	return (ft_convert(isnegative, n, allchars));
}
