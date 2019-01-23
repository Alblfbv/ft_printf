/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_stock_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 10:50:02 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/23 13:04:11 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wc_field_width(t_conv_spec *conv_spec, va_list *ap)
{
	conv_spec->field_width = va_arg(*ap, int);
}

void	ft_wc_precision(t_conv_spec *conv_spec, va_list *ap)
{
	conv_spec->precision = va_arg(*ap, int);
}

void	ft_field_width(t_conv_spec *conv_spec, char *format, int i, int len)
{
	while (len > 0)
	{
		if (format[i] >= '1' && format[i] <= '9' && format[i - 1] != '.')
		{
			while (format[i] >= '0' && format[i] <= '9')
			{
				conv_spec->field_width =
				conv_spec->field_width * 10 + (format[i] - 48);
				i++;
				len--;
			}
			return ;
		}
		i++;
		len--;
	}
}

void	ft_precision(t_conv_spec *conv_spec, char *format, int i, int len)
{
	while (len > 0)
	{
		if (format[i] == '.')
		{
			conv_spec->precision = 0;
			i++;
			len--;
			while (format[i] >= '0' && format[i] <= '9')
			{
				conv_spec->precision =
				(conv_spec->precision * 10) + (format[i] - 48);
				i++;
				len--;
			}
			return ;
		}
		i++;
		len--;
	}
}
