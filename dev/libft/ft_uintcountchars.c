/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_uintcountchars.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/08 13:04:04 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/05/08 13:04:06 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_uintcountchars(unsigned int n)
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
