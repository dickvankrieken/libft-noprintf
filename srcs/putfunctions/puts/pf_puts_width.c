#include "../../../includes/ft_printf.h"

void	pf_puts_width(t_convert *p)
{
	if (p->zero)
		pf_puts_width_zero(p);
	else
	{
		if (p->precision)
		{
			write(1, p->s, p->precision);
			pf_putspaces(p->width - p->precision);
		}
		else
		{
			pf_putspaces(p->width - ft_strlen(p->s));
			write(1, p->s, ft_strlen(p->s));
		}
	}
	p->count += p->width;
}

void	pf_puts_width_zero(t_convert *p)
{
	if (p->precision > -1)
	{
		pf_putzero(p->width - p->precision);
		write(1, p->s, p->precision);
	}
	else
	{
		pf_putzero(p->width - ft_strlen(p->s));
		write(1, p->s, ft_strlen(p->s));
	}
}
