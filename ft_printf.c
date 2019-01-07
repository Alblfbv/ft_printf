/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:05:30 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/07 15:45:49 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_management(char *format, int *i, int ret)
{
	t_conv_spec		conv_spec;
	int				j;

	j = 0;
	ft_conv_id(&conv_spec, format, *i);
	*i = *i + 1;
	/*FT_TYPE(&conv_spec, format, i);
	FT_FLAG(&conv_spec, format, i);
	FT_FIELD_WIDTH(&conv_spec, format, i);
	FT_PRECISION(&conv_spec, format, i);
	FT_LENGTH_MODIFIER(&conv_spec, format, i); */
	ft_putchar(conv_spec.conv_id);
	return (ret);
}

int		ft_print_ordinary(char *format, int *i, int ret)
{
	while (format[*i] != '%' && format[*i] != '\0')
	{
		//ft_putchar(format[*i]);
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
			if ((ret = ft_conv_management(format, &i, ret) == -1))
				return (-1);
		}
	}
	va_end(ap);
	return (ret);
}

int		main(void)
{
	ft_printf("Hello %gggggfggg");
	return (0);
}
