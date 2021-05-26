#include "../../includes/ft_printf.h"

static void	pf_putx_width_zero(t_convert *p)
{
	if (p->precision > -1 && p->precision > (int)ft_strlen(p->s))
	{
		pf_putspaces(p, p->width - p->precision);
		pf_putzero(p, p->precision - ft_strlen(p->s));
		write(1, p->s, ft_strlen(p->s));
	}
	else if (p->precision > -1)
	{
		pf_putspaces(p, p->width - ft_strlen(p->s));
		write(1, p->s, ft_strlen(p->s));
	}
	else
	{
		pf_putzero(p, p->width - ft_strlen(p->s));
		write(1, p->s, ft_strlen(p->s));
	}
	p->count += (int)ft_strlen(p->s);
}

static void	pf_putx_width(t_convert *p)
{
	if (p->zero)
		pf_putx_width_zero(p);
	else
	{
		if (p->precision > -1 && p->precision > (int)ft_strlen(p->s))
		{
			if (p->width > p->precision)
			{
				pf_putspaces(p, p->width - p->precision);
			}
			pf_putx_precision(p);
			return ;
		}
		else if (p->precision == 0)
		{
			pf_putspaces(p, p->width);
			return ;
		}
		else if (p->width > (int)ft_strlen(p->s))
		{
			pf_putspaces(p, p->width - ft_strlen(p->s));
		}
		write(1, p->s, ft_strlen(p->s));
		p->count += ft_strlen(p->s);
	}
}

static void	pf_putx_minus_width(t_convert *p)
{
	if (p->precision == 0)
	{
		pf_putspaces(p, p->width);
	}
	else if (p->precision > -1 && p->precision < (int)ft_strlen(p->s))
	{
		write(1, p->s, ft_strlen(p->s));
		p->count += ft_strlen(p->s);
		if (p->width > p->precision)
			pf_putspaces(p, p->width - ft_strlen(p->s));
	}
	else if (p->precision > (int)ft_strlen(p->s))
	{
		pf_putx_precision(p);
		if (p->width > p->precision)
		{
			pf_putspaces(p, p->width - p->precision);
		}
	}
	else
	{
		write(1, p->s, ft_strlen(p->s));
		p->count += ft_strlen(p->s);
		pf_putspaces(p, p->width - (int)ft_strlen(p->s));
	}
}

static void	pf_putx_minus(t_convert *p)
{
	if (p->width)
		pf_putx_minus_width(p);
	else if (p->precision > -1 && p->precision < (int)ft_strlen(p->s))
	{
		p->count += write(1, p->s, p->precision);
	}
	else
	{
		p->count += write(1, p->s, ft_strlen(p->s));
	}
}

void	pf_putx(t_convert *p)
{
	int	i;
	int	len;

	if (p->precision == 0 && (p->x == 0 || p->X == 0) && !(p->width))
	{
		free(p->s);
		return ;
	}
	len = ft_strlen(p->s);
	i = 0;
	if (p->s)
	{
		if (p->minus)
			pf_putx_minus(p);
		else if (p->width)
			pf_putx_width(p);
		else
			pf_putx_checkprecision(p);
	}
	free(p->s);
}
