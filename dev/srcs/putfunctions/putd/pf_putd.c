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

void	pf_putd(t_convert *p)
{
	int i;

	i = 0;
	if (p->minus)
		pf_putd_minus(p);
	else if (p->zero)
		pf_putd_zero(p);
	else if (p->width > (int)ft_strlen(ft_itoa(p->d)) && (p->precision > (int)ft_strlen(ft_itoa(p->d))))
	{
		pf_putd_width_precision(p);
	}
	else if (p->width > (int)ft_strlen(ft_itoa(p->d)))
	{
		while (i < p->width - (int)ft_strlen(ft_itoa(p->d)))
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		ft_putstr_fd(ft_itoa(p->d), 1);
	}
	else if (p->precision > (int)ft_strlen(ft_itoa(p->d)))
	{
		pf_putd_precision(p);
	}
	else
		ft_putstr_fd(ft_itoa(p->d), 1);
}

/* pf_putd_precision zet een getal in een bepaalde precisie. Het returnt het aantal karakters dat is geprint. */

int	pf_putd_precision(t_convert *p)
{
	int i;
	int len;

	len = ft_strlen(ft_itoa(p->d));
	i = 0;
	if (p->d < 0)
	{
		ft_putchar_fd('-', 1);
		i++;
		len--;
		p->d = -(p->d);
		/* 't getal was negatief dus de lengte van het getal was inclusief een minus maar die hebben we nu niet meer nodig dus len-- en p->d maken we positief omdat we de min al gezet hebben.*/
	}
	 /* als die precision groter is dan de strlen van het getal (zonder een eventuele minus als het een negatief getal is), dan wordt het getal uitgebreid met vooraanstaande nullen */
	while (p->precision > len)
	{
		ft_putchar_fd('0', 1);
		len++;
		i++;
	}
	/* nu gaat het getal gezet worden */
	ft_putstr_fd(ft_itoa(p->d), 1);
	i += ft_strlen(ft_itoa(p->d));
	return (i);
}

void	pf_putd_width_precision(t_convert *p)
{
	/* er is een width en een precision
	als de width groter is dan de precision, dan worden er spaties gezet */
	int i;

	i = 0;
	if (p->width > p->precision)
	{
		if (p->d < 0)
			i++;
		while (i < p->width - p->precision)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	pf_putd_precision(p);
}

/*
helperfuncties in andere files

in pf_putd_minus.c
void	pf_putd_minus_width_precision(t_convert *p);
void	pf_putd_minus_width(t_convert *p);

in pf_putd_zero.c
void	pf_putd_zero_width_precision(t_convert *p);
void	pf_putd_zero_width(t_convert *p);
void	pf_putd_zero_precision(t_convert *p);
void	pf_putd_zero(t_convert *p);
*/
