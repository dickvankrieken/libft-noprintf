#include "../../../includes/ft_printf.h"

<<<<<<< HEAD:dev/srcs/putfunctions/puts/pf_s_minus_with_precision.c
void	pf_s_width_minus_checkprecision(t_convert *p)
{}
=======
void	pf_s_width_minus_checkprecision(p->s)
{
}
>>>>>>> 1721e647022fbbd43bb4721604cfa8fef7601545:dev/srcs/putfunctions/pf_s_minus_with_precision.c

void	pf_s_minus_with_precision(t_convert *p)
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
}

void	pf_s_minus_noprecision(t_convert *p)
{

}

void	pf_s_width_checkzero(t_convert *p)
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
