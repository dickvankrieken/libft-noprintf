#include "../../../includes/ft_printf.h"

static	void	pf_putx_width(t_convert *p, int len)
{
	int i;

	i = 0;
	while (i < (p->width - p->precision))
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		while (p->precision > len && i < (p->width - len))
		{
			ft_putchar_fd('0', 1);
			i++;
		}
}

void		pf_putx(t_convert *p, int isupper)
{
	char *string;
	int len;
	int i;

	if (isupper)
		string = pf_ultohex(p->X, isupper);
	else
		string = pf_ultohex(p->x, isupper);
	len = ft_strlen(string);
	i = 0;
	if (p->width > len)
	{
		pf_putx_width(p, len);
	}
	else if (p->precision > len)
	{
		i = len;
		while (p->precision > i)
		{
			ft_putchar_fd('0', 1);
			i++;
		}
	}
	ft_putstr_fd(string, 1);
}
