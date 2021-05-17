#include "../../../includes/ft_printf.h"

static void	pf_putc_width(t_convert *p)
{
	if (p->minus)
	{
		ft_putchar_fd(p->c, 1);
		pf_putspaces(p->width - 1);
	}
	else if (p->zero)
	{
		pf_putzero(p->width - 1);
		ft_putchar_fd(p->c, 1);
	}
	else
	{
		pf_putspaces(p->width - 1);
		ft_putchar_fd(p->c, 1);
	}
	p->count += p->width;
}

void		pf_putc(t_convert *p)
{
	int i;

	i = 0;
	if (p->width)
	{
		pf_putc_width(p);
	}
	else
	{
		ft_putchar_fd(p->c, 1);
		p->count++;
	}
}
