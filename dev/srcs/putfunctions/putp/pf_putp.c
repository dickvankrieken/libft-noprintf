#include "../../../includes/ft_printf.h"
#include <stdlib.h>


/* ? in sommige gevallen is de nul en precision allemaal undefined behaviour voor %p */

void	pf_putp(t_convert *p)
{
	ft_putstr_fd(pf_ultohex(p->p), 1);
}
