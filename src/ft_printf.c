/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:05:30 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/07 18:57:19 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_management(char *format, int *i, int ret, va_list *ap)
{
	t_conv_spec		conv_spec;
	int				len;

	len = ft_conv_id(&conv_spec, format, *i);
	ft_param_value(&conv_spec, ap);
	ft_flag(&conv_spec, format, *i, len);
	ft_size_modif(&conv_spec, format, *i, len);
	ft_field_width(&conv_spec, format, *i, len);
	ft_precision(&conv_spec, format, *i, len);
	*i = *i + 1;
	return (ret);
}

int		ft_print_ordinary(char *format, int *i, int ret)
{
	while (format[*i] != '%' && format[*i] != '\0')
	{
		*i = *i + 1;
		ret++;
	}
	return (ret);
}

int		ft_printf(char *format, ...)
{
	va_list	ap;
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_putchar('%');
			i = i + 2;
		}
		else if(format[i] != '%')
			ret = ft_print_ordinary(format, &i, ret);
		else
		{
			if ((ret = ft_conv_management(format, &i, ret, &ap) == -1))
				return (-1);
		}
	}
	va_end(ap);
	return (ret);
}

int		main(void)
{
	ft_printf("Heo %.111+456.123+123llhh+++++++++++---------------------------d", 5);
	ft_printf("%.500d", 5);
	return (0);
}
