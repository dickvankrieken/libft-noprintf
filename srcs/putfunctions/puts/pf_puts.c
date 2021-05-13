#include "../../../includes/ft_printf.h"

void	pf_puts(t_convert *p)
{
	int i;
	int len;

	len = ft_strlen(p->s);
	i = 0;
	if (p->s)
	{
		if (p->width)
		{
			pf_puts_width(p);
		}
		else
		{
			if (p->precision)
			{
				write(1, p->s, p->precision);
				if (p->precision < (int)ft_strlen(p->s))
					p->printcounter += p->precision;
				else
					p->printcounter += ft_strlen(p->s);
			}
			else
				write(1, p->s, ft_strlen(p->s));
		}
	}
}
