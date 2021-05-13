#include "../../../includes/ft_printf.h"

void	pf_putp(t_convert *p)
{
	char *string;
	int len;

	string = pf_ultohex(p->p, 0);
	len = ft_strlen(string) + 2;
	while (p->width > len)
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(string, 1);
}
