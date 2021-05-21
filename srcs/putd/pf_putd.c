#include "../../includes/ft_printf.h"

void	pf_putd_width_precision(t_convert *p)
{
	int i;

	i = 0;
	if (p->width > p->precision)
	{
		if (p->d < 0)
			i++;
		if (p->precision > ft_intcountchars(p->d))
		{
			while (i < p->width - p->precision)
			{
				ft_putchar_fd(' ', 1);
				i++;
				p->count++;
			}
		}
		else
		{
			while (i < p->width - ft_intcountchars(p->d))
			{
				ft_putchar_fd(' ', 1);
				i++;
				p->count++;
			}
		}
	}
	pf_putd_precision(p);
}

int	pf_putd_precision(t_convert *p)
{
	int i;
	int len;

	len = ft_intcountchars(p->d);
	i = 0;
	if (p->precision)
	{
		if (p->precision > ft_intcountchars(p->d))
		{
			if (p->d < 0)
			{
				ft_putchar_fd('-', 1);
				i++;
				len--;
				p->d = -(p->d);
			}
			while (p->precision > len)
			{
				ft_putchar_fd('0', 1);
				len++;
				i++;
			}
		}
		ft_putnbr_fd((p->d), 1);
		i += ft_intcountchars(p->d);
		p->count += i;
	}
	return (i);
}

void	pf_putd_width(t_convert *p)
{
	int i;

	if (p->precision > ft_intcountchars(p->d))
		pf_putd_width_precision(p);
	else
	{
		i = 0;
		while (i < p->width - ft_intcountchars(p->d))
		{
			ft_putchar_fd(' ', 1);
			i++;
			p->count++;
		}
		if (p->precision)
		{
			ft_putnbr_fd((p->d), 1);
			p->count += ft_intcountchars(p->d);
		}
		else
		{
			ft_putchar_fd(' ', 1);
			i++;
			p->count++;
		}
	}
}

void	pf_putd(t_convert *p)
{
	int i;

	i = 0;
	if (p->minus)
		pf_putd_minus(p);
	else if (p->zero && !(p->precision > -1))
		pf_putd_zero(p);
	else if (p->width > ft_intcountchars(p->d))
		pf_putd_width(p);
	else if (p->precision > -1)
		pf_putd_precision(p);
	else
	{
		ft_putnbr_fd((p->d), 1);
		p->count += ft_intcountchars(p->d);
	}
}
