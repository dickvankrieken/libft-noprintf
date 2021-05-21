#include "../includes/ft_printf.h"

void	pf_printp(t_convert *p)
{
	ft_putstr_fd("0x", 1);
	p->count += 2;
	if (!p->p)
	{
		ft_putchar_fd('0', 1);
		p->count++;
		return ;
	}
	ft_putstr_fd(p->s, 1);
	p->count += (int)ft_strlen(p->s);
}

void	pf_putp(t_convert *p)
{
	int		len;

	p->s = pf_ultohex(p->p, 0);
	if (p->minus)
		pf_printp(p);
	if (p->p)
		len = ft_strlen(p->s) + 2;
	else
		len = 3;
	while (p->width > len)
	{
		ft_putchar_fd(' ', 1);
		len++;
		p->count++;
	}
	if (!p->minus)
		pf_printp(p);
}
