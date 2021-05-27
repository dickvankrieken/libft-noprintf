/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putx_minus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 22:20:33 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/05/27 22:20:36 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	pf_putx_minus_width_precision(t_convert *p)
{
	int	i;

	pf_putx_precision(p);
	i = p->count;
	while (i < p->width)
	{
		ft_putchar_fd(' ', 1);
		i++;
		p->count++;
	}
}

static void	pf_putx_minus_width(t_convert *p)
{
	int	i;

	ft_putnbr_fd((p->d), 1);
	p->count += ft_intcountchars(p->d);
	i = 0;
	while (i < p->width - ft_intcountchars(p->d))
	{
		ft_putchar_fd(' ', 1);
		i++;
		p->count++;
	}
}

void	pf_putx_minus(t_convert *p)
{
	if (p->width)
	{
		if (p->precision)
		{
			pf_putx_minus_width_precision(p);
		}
		else
			pf_putx_minus_width(p);
	}
	else if (p->precision > ft_intcountchars(p->d))
	{
		pf_putx_precision(p);
	}
	else
	{
		ft_putnbr_fd((p->d), 1);
		p->count += ft_intcountchars(p->d);
	}
}
