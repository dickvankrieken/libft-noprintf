#include "../../../includes/ft_printf.h"

static void	pf_puts_checkprecision(t_convert *p)
{
	if (p->precision)
	{
		write(1, p->s, p->precision);
		if (p->precision < (int)ft_strlen(p->s))
			p->count += p->precision;
		else
			p->count += ft_strlen(p->s);
	}
	else
	{
		write(1, p->s, ft_strlen(p->s));
		p->count += (int)ft_strlen(p->s);
	}
}

void		pf_puts(t_convert *p)
{
	int i;
	int len;

	len = ft_strlen(p->s);
	i = 0;
	if (p->s)
	{
		if (p->minus)
		{
			pf_puts_minus(p);
		}
		else if (p->width)
		{
			pf_puts_width(p);
		}
		else
		{
			pf_puts_checkprecision(p);
		}
	}
}
