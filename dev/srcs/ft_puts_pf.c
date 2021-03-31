#include "../includes/ft_printf.h"

void	ft_puts_pf(t_convert *conv_specs)
{
	int i;
	int len;

	len = ft_strlen(conv_specs->s);
	i = 0;
	if (conv_specs->s)
	{
		if (conv_specs->width)
		{
			if (conv_specs->minus)
			{
				write(1, conv_specs->s, ft_strlen(conv_specs->s));
				ft_putspaces_pf(conv_specs->width - ft_strlen(conv_specs->s));
			}
			else
			{
				if (conv_specs->precision > -1)
				{
					while (i < conv_specs->precision && i < len)
					{
						write(1, conv_specs->s, 1);
						conv_specs->s++;
						conv_specs->printcounter++;
						i++;
					}
				}
				ft_putspaces_pf(conv_specs->width - ft_strlen(conv_specs->s));
				write(1, conv_specs->s, ft_strlen(conv_specs->s));
			}
		}
		else
		{
			write(1, conv_specs->s, ft_strlen(conv_specs->s));
			conv_specs->printcounter += ft_strlen(conv_specs->s);
		}
	}
}

void	ft_putspaces_pf(int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(' ', 1);
		i++;
	}
}
