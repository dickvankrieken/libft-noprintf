/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 17:44:10 by dvan-kri      #+#    #+#                 */
/*   Updated: 2020/11/27 11:54:36 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n > 0)
	{
		n--;
		*((char*)dst) = *((char*)src);
		if (*((char*)src) == (char)c)
			return (dst + 1);
		dst++;
		src++;
	}
	return (NULL);
}
