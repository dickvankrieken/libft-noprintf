#include "../../../includes/ft_printf.h"

void	pf_puts_width(t_convert *p)
{
	if (p->minus)
		pf_puts_width_minus_checkprecision(p);
	else if (p->zero)
		pf_puts_width_checkzero(p);
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
	p->printcounter += p->width;
}

void	pf_puts_width_checkzero(t_convert *p)
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


void	pf_puts_width_minus_checkprecision(t_convert *p)
{}