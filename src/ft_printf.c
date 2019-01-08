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

int		ft_struct_create(t_conv_spec *conv_spec, char *format, int *i, va_list *ap)
{
	int	len;

	len = ft_conv_id(conv_spec, format, *i);
	ft_param_value(conv_spec, ap);
	ft_flag(conv_spec, format, *i, len);
	ft_size_modif(conv_spec, format, *i, len);
	ft_field_width(conv_spec, format, *i, len);
	ft_precision(conv_spec, format, *i, len);
	return (len);
}

void	ft_conv_management(char *format, int *i, va_list *ap)
{
	t_conv_spec		conv_spec;
	int				len;

	len = ft_struct_create(&conv_spec, format, i, ap);
	//FT_CONVERSION();
	*i = *i + len;
}

int		ft_printf(char *format, ...)
{
	va_list	ap;
	char	*result;
	int		i;
	int		j;
	int		ret;

	i = 0;
	ret = 0;
	result = ft_strnew(1);
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			result = ft_strextend(result, "%");
			i = i + 2;
		}
		else if(format[i] != '%')
		{
			j = (ft_strchr((format + i), '%') - (format + i));
			result = ft_strnextend(result, (format + i), j);
			i = i + j;
			printf("i after ordinary = %d\n", i);
		}
		else
		{
			ft_conv_management(format, &i, &ap);
			printf("i after %% management function = %d\n", i);
		}
	}
	printf("%s", result);
	va_end(ap);
	return (ret);
}

int		main(void)
{
	ft_printf("Heo %12345d3llhh++++++%+++++---------------------------d", 5, 5);
	return (0);
}
