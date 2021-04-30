#include "../../../includes/ft_printf.h"

void	pf_putx(t_convert *p, int isupper)
{
	char *string;

	int len;
	if (isupper)
		string = pf_ultohex(p->X, isupper);
	else
		string = pf_ultohex(p->x, isupper);
	len = ft_strlen(string);
	while (p->width > len)
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	ft_putstr_fd(string, 1);
}
