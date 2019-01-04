/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:05:30 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/04 18:28:38 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_spec_tab(char format_c)
{
	if (format_c == 'd' || 
		format_c == 'i' ||
		format_c == 'o' ||
		format_c == 'u' ||
		format_c == 'x' ||
		format_c == 'X' ||
		format_c == 'c' ||
		format_c == 's' ||
		format_c == 'p' ||
		format_c == 'f')
		return (1);
	return (0);
}

int		ft_conv_management(char *format, int *i, int ret)
{
	char	*conv_spec;
	int		j;

	j = 0;
	while (ft_spec_tab(format[*i]) != 1 && format[*i] != '\0')
	{
		j++;
		*i = *i + 1;
	}
	*i = *i + 1;
	if (format[*i] == '\0')
		return (ret);
	if (!(conv_spec = ft_strndup(format + *i - j, j)))
		return (-1);

	ft_putstr(conv_spec);
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
