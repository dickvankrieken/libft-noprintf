#include "../../../includes/ft_printf.h"


void	pf_puts_minus(t_convert *p)
{

}

void	pf_puts_minus_width_precision(t_convert *p)
{
	if (p->precision > -1)
	{
		write(1, p->s, p->precision);
		pf_putspaces(p->width - p->precision);
	}
	else
	{
		write(1, p->s, ft_strlen(p->s));
		pf_putspaces(p->width - ft_strlen(p->s));
	}
}

void	pf_puts_minus_noprecision(t_convert *p)
{

}

