#include "../libft/libft.h"
#include "../includes/ft_printf.h"

void ft_putrightjustification(t_convert *conv_specs)
{
	/* while (conv_specs->printcounter < conv_specs->width - conv_specs->arg_length) */
	/* { */

	/* } */
}

/* probleem is nu: hoeveel putchars neerzetten terwijl je niet weet hoe veel ruimte dat variatische argument in moet gaan nemen... */
void ft_putleftjustification(t_convert *conv_specs)
{
	while (conv_specs->printcounter < conv_specs->width)
	{
		ft_putchar_fd(' ', 1);
		conv_specs->printcounter++;
	}
}

void ft_put_arg(t_convert *conv_specs)
{
	if (conv_specs->type == 'c')
		ft_putchar_fd(conv_specs->c, 1);
	if (conv_specs->type == 's')
		ft_putstr_fd(conv_specs->s, 1);
	/* if (conv_specs->type == 'p') */
	/* 	conv_specs->p = va_arg(conv_specs->ap, char *); */
	/* if (conv_specs->type == 'd') */
	/* 	conv_specs->d = va_arg(conv_specs->ap, int); */
	/* if (conv_specs->type == 'i') */
	/* 	conv_specs->i = va_arg(conv_specs->ap, int); */
	/* if (conv_specs->type == 'u') */
	/* 	conv_specs->u = va_arg(conv_specs->ap, unsigned int); */
	/* if (conv_specs->type == 'x') */
	/* 	conv_specs->u = va_arg(conv_specs->ap, unsigned int); */
	/* if (conv_specs->type == 'X') */
	/* 	conv_specs->u = va_arg(conv_specs->ap, unsigned int); */
}

/* we gaan eerst een stukje verwerken wat voor ieder conversie type geldt: de width en de 0 en - flags.*/
void	ft_putconversion(t_convert *conv_specs)
{
	if (conv_specs->width)
	{
		if (conv_specs->minus)
		{
			/* als het goed is houd ft_put_arg bij hoeveel hij geprint heeft. Zodat vervolgens het restant volgezet kan worden met spaties of nullen */
			ft_put_arg(conv_specs);
//			ft_putjustification(conv_specs);
		}
		else
		{

		}


		//	if (!conv_specs->minus)

//			ft_put_arg(conv_specs);
	}

	ft_put_arg(conv_specs);

}

void	ft_putchar_pf(char c, t_convert *conv_specs)
{
	write(1, &c, sizeof(char));
	conv_specs->printcounter++;
}
