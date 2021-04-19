#include "../../../includes/ft_printf.h"

void	pf_putd_zero(t_convert *p)
{
	if (p->width > ft_strlen(ft_itoa(p->d)))
	{
		if (p->precision)
		{
			pf_putd_zero_width_precision(p);
		}
		pf_putd_zero_width(p);
	}
	if (p->precision > ft_strlen(ft_itoa(p->d)))
	{
		pf_putd_zero_precision(p);
	}
	else
	{
		ft_putstr_fd(ft_itoa(p->d), 1);
	}
}

void	pf_putd_zero_width(t_convert *p)
{

}

void	pf_putd_zero_width_precision(t_convert *p)
{

}

void	pf_putd_zero_precision(t_convert *p)
{

}
