#include "../includes/ft_printf.h"

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
			if (p->minus)
			{
				write(1, p->s, ft_strlen(p->s));
				pf_putspaces(p->width - ft_strlen(p->s));
			}
			else if (p->zero)
			{
				pf_putzero(p->width - ft_strlen(p->s));
			}
			else
			{
				pf_putspaces(p->width - ft_strlen(p->s));
				if (p->precision > -1)
				{
					while (i < p->precision && i < len)
					{
						write(1, p->s, 1);
						p->s++;
						p->printcounter++;
						i++;
					}
				}
				write(1, p->s, ft_strlen(p->s));
			}
		}
		else
		{
			write(1, p->s, ft_strlen(p->s));
			p->printcounter += ft_strlen(p->s);
		}
	}
}
