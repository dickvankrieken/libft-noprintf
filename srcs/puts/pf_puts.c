#include "../../includes/ft_printf.h"

static void	pf_puts_checkprecision(t_convert *p)
{
	if (p->precision > -1)
	{
		if (p->precision < (int)ft_strlen(p->s))
		{
			write(1, p->s, p->precision);
			p->count += p->precision;
		}
		else
		{
			write(1, p->s, ft_strlen(p->s));
			p->count += ft_strlen(p->s);
		}
	}
	else
	{
		write(1, p->s, ft_strlen(p->s));
		p->count += (int)ft_strlen(p->s);
	}
}

static void	pf_puts_width_zero(t_convert *p)
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

static void	pf_puts_width(t_convert *p)
{
	if (p->zero)
		pf_puts_width_zero(p);
	else
	{
		if (p->precision > -1)
		{
			if (p->precision < (int)ft_strlen(p->s))
			{
				pf_putspaces(p->width - p->precision);
				write(1, p->s, p->precision);
			}
			else
			{
				pf_putspaces(p->width - ft_strlen(p->s));
				write (1, p->s, ft_strlen(p->s));
			}
		}
		else
		{
			pf_putspaces(p->width - ft_strlen(p->s));
			write(1, p->s, ft_strlen(p->s));
		}
	}
	p->count += p->width;
}

static void	pf_puts_minus(t_convert *p)
{
	if (p->width)
	{
		if (p->precision > -1 && p->precision < (int)ft_strlen(p->s))
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
