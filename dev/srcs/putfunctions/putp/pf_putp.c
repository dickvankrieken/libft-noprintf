#include "../../../includes/ft_printf.h"


/* ? in sommige gevallen is de nul en precision allemaal undefined behaviour voor %p
 nu worden er eigenlijk in het geheel geen flags behandeld voor deze conversie en ik weet niet of dat ok is. */

void	pf_putp(t_convert *p)
{
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(pf_ultohex(p->p, 0), 1);
}
