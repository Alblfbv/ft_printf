/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:30:04 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/15 11:59:12 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_cal_nb(t_conv_spec conv_spec, double nb)
{
	int		a;
	int		b;
	
	a = 6;
	b = 0;
	if (conv_spec.precision == -1)
			b = nb * 1000000;
	else
	{
		ft_putchar('A');
		while (conv_spec.precision > 0)
		{
			nb = nb * 10;
			ft_putchar('A');
			conv_spec.precision--;
		}
		b = nb;
	}
	b++;
	return (b);
}

char			*ft_process_f(t_conv_spec conv_spec, va_list *ap)
{
	char	*str;
	char	*str2;
	int		tmp;
	double	nb;

	nb = va_arg(*ap, double);
	tmp = nb;
	str = ft_itoa(tmp);
	str2 = ft_strdup(".");
	str2 = ft_strextend(str, str2);
	nb = nb - tmp;
	tmp = ft_cal_nb(conv_spec, nb);

	str = ft_itoa(tmp);
	str = ft_strextend(str2, str);
	return (str);
}

