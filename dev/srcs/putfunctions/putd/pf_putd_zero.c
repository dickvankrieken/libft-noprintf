#include "../../../includes/ft_printf.h"

void	pf_putd_zero(t_convert *p)
{
	if (p->width > ft_strlen(ft_itoa(p->d)))
	{
<<<<<<< HEAD
		/* if (p->precision >= 0) */
		/* { */
		/* 	/\* als de width groter is dan de precision, dan worden er spaties gezet *\/ */
		/* 	pf_putd_width_precision(p); */
		/* 	/\* ? welke functie komt hier ? pf_putd_width_precision(p); *\/ */
		/* } */
		/* ft_putchar_fd('!', 1); */
		if (p->precision >= 0)
			pf_putd_width_precision(p);
		else
			pf_putd_zero_width(p);
=======
		if (p->precision)
		{
		pf_putd_zero_width_precision(p);
		}
		pf_putd_zero_width(p);
>>>>>>> 56ab94e0bfe1e87f15b77c0e235e52acf044c59c
	}
	else if (p->precision > ft_strlen(ft_itoa(p->d)))
	{
		pf_putd_precision(p);
	}
	else
	{
		ft_putstr_fd(ft_itoa(p->d), 1);
	}
}

void	pf_putd_zero_width(t_convert *p)
{
	int i;

	i = 0;
	if (p->d < 0)
	{
		ft_putchar_fd('-', 1);
		i++;
		p->d = -(p->d);
		/* 't getal was negatief dus de lengte van het getal was inclusief een minus maar die hebben we nu niet meer nodig dus len-- en p->d maken we positief omdat we de min al gezet hebben.*/
	}
	 /* als die precision groter is dan de strlen van het getal (zonder een eventuele minus als het een negatief getal is), dan wordt het getal uitgebreid met vooraanstaande nullen */
	while (p->width > i + ft_strlen(ft_itoa(p->d)))
	{
		ft_putchar_fd('0', 1);
		i++;
	}
	/* nu gaat het getal gezet worden */
	ft_putstr_fd(ft_itoa(p->d), 1);
	i += ft_strlen(ft_itoa(p->d));
	/* wat gaan we met de i doen? het aantal gezette karakters houden we misschien bij in de struct maar we weten nog niet zo goed waarom we die zouden moeten bijhouden, misschien hoeft dat in mijn project wel helemaal niet */
}

/* void	pf_putd_zero_precision(t_convert *p) */
/* { */
/* 	int i; */

/* 	i += pf_putd_precision(p); */
/* } */
