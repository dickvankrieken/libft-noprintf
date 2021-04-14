#include "../../includes/ft_printf.h"

<<<<<<< HEAD:dev/srcs/putfunctions/puts/pf_puts_ifwidth.c
void	pf_puts_ifwidth(t_convert *p)
=======
void	pf_puts(t_convert *p)
{
	int i;
	int len;

	len = ft_strlen(p->s);
	i = 0;
	if (p->s)
	{
		if (p->width)
>>>>>>> 1721e647022fbbd43bb4721604cfa8fef7601545:dev/srcs/putfunctions/pf_puts.c
		{
			if (p->minus)
				pf_s_width_minus_checkprecision(p->s);
			else if (p->zero)
				pf_s_width_checkzero(p->s);
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
<<<<<<< HEAD:dev/srcs/putfunctions/puts/pf_puts_ifwidth.c
=======
		else
		{
			if (p->precision)
			{
				write(1, p->s, p->precision);
				if (p->precision < ft_strlen(p->s))
					p->printcounter += p->precision;
				else
					p->printcounter += ft_strlen(p->s);
			}
			else
				write(1, p->s, ft_strlen(p->s));
		}


	}
}
>>>>>>> 1721e647022fbbd43bb4721604cfa8fef7601545:dev/srcs/putfunctions/pf_puts.c
