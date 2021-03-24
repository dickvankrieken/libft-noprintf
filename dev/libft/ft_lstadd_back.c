/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/22 21:28:56 by dvan-kri      #+#    #+#                 */
/*   Updated: 2020/11/22 22:34:00 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *getlast;

	if (lst && (*lst) && new)
	{
		getlast = ft_lstlast(*lst);
		getlast->next = new;
	}
	else
		*lst = new;
}
