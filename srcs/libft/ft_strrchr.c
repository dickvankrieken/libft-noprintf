/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 09:12:43 by dvan-kri      #+#    #+#                 */
/*   Updated: 2020/11/27 11:57:43 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*p;

	len = (ft_strlen(s));
	p = (char *)s;
	while (len >= 0)
	{
		if (*(p + len) == (char)c)
			return (p + len);
		len--;
	}
	return (NULL);
}
