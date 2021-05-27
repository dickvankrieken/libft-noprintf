/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putu_minus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 22:20:19 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/05/27 22:20:21 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	pf_putu_minus_width(t_convert *p)
{
	int	i;

	ft_putuint_fd((p->u), 1);
	p->count += ft_uintcountchars(p->u);
	i = ft_uintcountchars(p->u);
	while (i < p->width)
	{
		ft_putchar_fd(' ', 1);
		i++;
		p->count++;
	}
}

static void	pf_putu_minus_width_precision(t_convert *p)
{
	int	i;

	i = 0;
	if (p->precision != 0)
		i += pf_putu_precision(p);
	while (i < p->width)
	{
		ft_putchar_fd(' ', 1);
		i++;
		p->count++;
	}
}

void	pf_putu_minus(t_convert *p)
{
	if (p->width)
	{
		if (p->precision > -1)
			pf_putu_minus_width_precision(p);
		else
			pf_putu_minus_width(p);
	}
	else if (p->precision > ft_uintcountchars(p->d))
		pf_putu_precision(p);
	else
	{
		ft_putuint_fd((p->u), 1);
		p->count += ft_uintcountchars(p->u);
	}
}
