#include "../../../includes/ft_printf.h"

void	pf_putu_zero(t_convert *p)
{
	if (p->width > (int)ft_strlen(ft_uitoa(p->u)))
	{
		if (p->precision >= 0)
			pf_putu_width_precision(p);
		else
			pf_putu_zero_width(p);
	}
	else if (p->precision > (int)ft_strlen(ft_uitoa(p->u)))
	{
		pf_putu_precision(p);
	}
	else
	{
		ft_putuint_fd((p->u), 1);
	}
}

void	pf_putu_zero_width(t_convert *p)
{
	int i;

	i = 0;
	if (p->u < 0)
	{
		ft_putchar_fd('-', 1);
		i++;
		p->u = -(p->u);
		/* 't getal was negatief dus de lengte van het getal was inclusief een minus maar die hebben we nu niet meer nodig dus len-- en p->u maken we positief omdat we de min al gezet hebben.*/
	}
	 /* als die precision groter is dan de strlen van het getal (zonder een eventuele minus als het een negatief getal is), dan wordt het getal uitgebreid met vooraanstaande nullen */
	while (p->width > (int)(i + ft_strlen(ft_uitoa(p->u))))
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	/* nu gaat het getal gezet worden */
	ft_putuint_fd((p->u), 1);
	i += ft_strlen(ft_uitoa(p->u));
	/* wat gaan we met de i doen? het aantal gezette karakters houden we misschien bij in de struct maar we weten nog niet zo goed waarom we die zouden moeten bijhouden, misschien hoeft dat in mijn project wel helemaal niet */
}
