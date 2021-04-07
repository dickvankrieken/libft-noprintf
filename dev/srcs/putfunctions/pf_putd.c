void	pf_putd(t_convert *p)
{
	if (p->d)
	{
		ft_putstr_fd(ft_itoa(p->d));
	}
	else if (p->i)
	{
		ft_putstr_fd(ft_itoa(p->i));
	}
}
