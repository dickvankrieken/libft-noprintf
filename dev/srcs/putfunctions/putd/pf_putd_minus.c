
void	pf_putd_minus(t_convert *p)
{
	if (p->width > ft_strlen(ft_itoa(p->d)))
	{
		if (p->precision)
		{
			pf_putd_minus_width_precision(p);
		}
		pf_putd_minus_width(p);
	}
	if (p->precision > ft_strlen(ft_itoa(p->d)))
	{
		pf_putd_minus_precision(p);
	}
	pf_putd_minus(p);
}


void	pf_putd_minus_width_precision(p);

void	pf_putd_minus_width(p);

void	pf_putd_minus_precision(p);

void	pf_putd_minus(p);
