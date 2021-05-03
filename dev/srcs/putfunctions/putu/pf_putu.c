#include "../../../includes/ft_printf.h"

void		pf_putu(t_convert *p)
{
	ft_putstr_fd(ft_uitoa(p->u), 1);
}
