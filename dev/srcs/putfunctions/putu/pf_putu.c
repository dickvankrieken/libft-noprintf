/*
put d gaat een getal zetten
als er een - is dan wordt de conversie links-uitgelijnd binnen de field
als er een 0 flag is , dan worden er leading nullen geplaatst
als er een 0 en een - is, dan wordt de 0 flag genegeerd.
Voor d, i, o, u, x, en X - als er een precisie gespecifieerd is dan wordt de 0 flag genegeerd.
En voor andere conversies is het gedrag ongedefinieerd.
Het int argument wordt geconverteerd naar een signed decimal in de stijl van [-]dddd de precisie specifieerd het minimale aantal getallen dat zal verschijnen; als de waarde die geconverteerd gaat worden in minder getallen gerepresenteerd kan worden, dan zal het uitgebreid worden met vooraanstaande nullen. De standaard precisie is 1. Het resultaat van het converteren van een 0 waarde met een precisie van 0, is geen karakters
*/

#include "../../../includes/ft_printf.h"

void	pf_putu(t_convert *p)
{
	printf("???");
	int i;

	i = 0;
	if (p->minus)
		pf_putu_minus(p);
	else if (p->zero)
		pf_putu_zero(p);
	else if (p->width > ft_uintcountchars(p->u)) && (p->precision > ft_uintcountchars(p->u))
	{
		pf_putu_width_precision(p);
	}
	else if (p->width > ft_uintcountchars(p->u))
	{
		while (i < p->width - ft_uintcountchars(p->u))
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		ft_putuint_fd((p->u), 1);
	}
	else if (p->precision > ft_uintcountchars(p->u))
	{
		pf_putu_precision(p);
	}
	else
		ft_putuint_fd((p->u), 1);
}

/* pf_putd_precision zet een getal in een bepaalde precisie. Het returnt het aantal karakters dat is geprint. */

int	pf_putu_precision(t_convert *p)
{
	int i;
	int len;

	len = ft_uintcountchars(p->u);
	i = 0;
	if (p->u < 0)
	{
		ft_putchar_fd('-', 1);
		i++;
		len--;
		p->u = -(p->u);
		/* 't getal was negatief dus de lengte van het getal was inclusief een minus maar die hebben we nu niet meer nodig dus len-- en p->u maken we positief omdat we de min al gezet hebben.*/
	}
	 /* als die precision groter is dan de strlen van het getal (zonder een eventuele minus als het een negatief getal is), dan wordt het getal uitgebreid met vooraanstaande nullen */
	while (p->precision > len)
	{
		ft_putchar_fd('0', 1);
		len++;
		i++;
	}
	/* nu gaat het getal gezet worden */
		ft_putuint_fd((p->u), 1);
	i += ft_uintcountchars(p->u);
	return (i);
}

void	pf_putu_width_precision(t_convert *p)
{
	/* er is een width en een precision
	als de width groter is dan de precision, dan worden er spaties gezet */
	int i;

	i = 0;
	if (p->width > p->precision)
	{
		if (p->u < 0)
			i++;
		while (i < p->width - p->precision)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	pf_putu_precision(p);
}
