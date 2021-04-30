#include "../../../includes/ft_printf.h"

void	pf_putx(t_convert *p, int isupper)
{
	if (isupper)
		ft_putstr_fd(pf_ultohex(p->X, 1), 1);
	else
		ft_putstr_fd(pf_ultohex(p->x, 0), 0);
}
