/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:05:30 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/07 18:39:03 by jfleury          ###   ########.fr       */
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
/*	FT_FIELD_WIDTH(&conv_spec, format, i);
	FT_PRECISION(&conv_spec, format, i);
	FT_LENGTH_MODIFIER(&conv_spec, format, i); */
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
		if (format[i] != '%')
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
	ft_printf("Hello %+++++++++++++---------------------------d", 5);
	return (0);
}
