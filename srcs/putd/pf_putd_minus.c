#include "../../includes/ft_printf.h"

static void	pf_putd_minus_width_precision(t_convert *p)
{
	int i;

	i = 0;
	i += pf_putd_precision(p);
	while (i < p->width)
	{
		ft_putchar_fd(' ', 1);
		i++;
		p->count++;
	}
}

static void	pf_putd_minus_width(t_convert *p)
{
	int i;

	i = 0;
	if (p->precision != 0)
	{
		ft_putnbr_fd((p->d), 1);
		p->count += ft_intcountchars(p->d);
	}
	else if (!(p->precision == 0 && p->d == 0))
	{
		ft_putchar_fd(' ', 1);
		i++;
		p->count++;
	}
	i = 0;
	while (i < p->width - ft_intcountchars(p->d))
	{
		ft_putchar_fd(' ', 1);
		i++;
		p->count++;
	}
}

void		pf_putd_minus(t_convert *p)
{

	if (p->width)
	{

		if (p->precision)
		{
			pf_putd_minus_width_precision(p);
		}
		else
			pf_putd_minus_width(p);
	}
	else if (p->precision > ft_intcountchars(p->d))
	{
		pf_putd_precision(p);
	}
	else
	{
		ft_putnbr_fd((p->d), 1);
		p->count += ft_intcountchars(p->d);
	}
}
