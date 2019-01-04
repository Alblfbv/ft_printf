/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 11:27:25 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/04 12:22:42 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	char		*s;
	int			d;

	i = 0;
	va_start(ap, format);
	while (format[i] != 0)
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			ft_putchar(format[i]);
			i++;
		}
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 's')
			{
				s = va_arg(ap, char*);
				ft_putstr(s);
				i++;
			}
			if (format[i] == 'd')
			{
				d = va_arg(ap, int);
				ft_putnbr(d);
				i++;
			}
		}
	}
	va_end(ap);
	return (0);
}

int		main(int ac, char **av)
{
	ft_printf("Hello %s blabla %d %%d %s \n", "CHAINE", 30, 25, "TEST");
}
