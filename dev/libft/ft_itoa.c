/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/20 11:36:48 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/05/06 12:54:45 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


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
			a[i] = (num % 10) + '0';
			num /= 10;
			i--;
		}
	}
	return (a);
}

char	*ft_itoa(int n)
{
	int		isnegative;
	int		allchars;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	isnegative = 0;
	if (n < 0)
		isnegative = 1;
	if (n == -0)
		return (ft_strdup("0"));
	allchars = ft_intcountchars(n);
	return (ft_convert(isnegative, n, allchars));
}
