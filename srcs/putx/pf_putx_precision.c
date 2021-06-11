/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_putx_precision.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-kri <dvan-kri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 22:20:39 by dvan-kri      #+#    #+#                 */
/*   Updated: 2021/06/11 11:59:04 by dvan-kri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	pf_putx_precision(t_convert *p)
{
	int	len;

	len = ft_strlen(p->s);
	if (p->precision > len)
	{
		pf_putzero(p, p->precision - len);
	}
	if (!(p->precision == 0 && (p->x == 0 || p->X == 0)))
	{
		ft_putstr_fd(p->s, 1);
		p->count += (int)ft_strlen(p->s);
	}
	else
		pf_putspaces(p, 1);
}

void	pf_putx_checkprecision(t_convert *p)
{
	if (p->precision > -1)
	{
		if (p->precision < (int)ft_strlen(p->s) && !(p->x == 0 || p->X == 0))
		{
			write(1, p->s, (int)ft_strlen(p->s));
			p->count += (int)ft_strlen(p->s);
		}
		else
		{
			pf_putx_precision(p);
		}
	}
	else
	{
		write(1, p->s, ft_strlen(p->s));
		p->count += (int)ft_strlen(p->s);
	}
}
