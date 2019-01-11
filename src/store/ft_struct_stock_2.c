/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_stock_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 10:50:02 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/08 10:55:34 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_field_width(t_conv_spec *conv_spec, char *format, int i, int len)
{
	conv_spec->field_width = 0;
	while (len > 0)
	{
		if (format[i] >= '1' && format[i] <= '9' && format[i - 1] != '.'
			&& (format[i - 1] < '0' || format[i - 1] > '9'))
		{
			while (format[i] >= '0' && format[i] <= '9')
			{
				conv_spec->field_width = conv_spec->field_width * 10 + (format[i] - 48);
				i++;
				len--;
			}
			return ;
		}
		i++;
		len--;
	}
}
