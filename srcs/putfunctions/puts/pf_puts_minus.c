#include "../../../includes/ft_printf.h"

void	pf_puts_minus(t_convert *p)
{
	if (p->width)
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
		p->count += p->width;
	}
	else if (p->precision > -1 && p->precision < (int)ft_strlen(p->s))
	{
		p->count += write(1, p->s, p->precision);
	}
	else
	{
 		p->count += write(1, p->s, ft_strlen(p->s));
	}
}
