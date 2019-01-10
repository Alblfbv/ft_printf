/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:05:30 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/10 16:38:55 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_process(t_conv_spec conv_spec, va_list *ap)
{
	char	*str;

	str = ft_process_table(conv_spec, ap);
	return (str);
}

int		ft_struct_create(t_conv_spec *conv_spec, char *format, int *i)
{
	int	len;

	len = ft_conv_id(conv_spec, format, *i);
	ft_flag(conv_spec, format, *i, len);
	ft_size_modif(conv_spec, format, *i, len);
	ft_field_width(conv_spec, format, *i, len);
	ft_precision(conv_spec, format, *i, len);
	return (len);
}

unsigned char	*ft_conv_management(char *format, int *i, va_list *ap, unsigned char *result)
{
	t_conv_spec		conv_spec;
	int				len;
	char			*str;

	ft_struct_init(&conv_spec);
	len = ft_struct_create(&conv_spec, format, i);
	str = ft_conv_process(conv_spec, ap);
	result = (unsigned char *)ft_strextend((char *)result, str);
	free(str);
	*i = *i + len + 1;
	ft_struct_del(&conv_spec);
	return (result);
}

unsigned char	*ft_ordinary_management(char *format, int *i, unsigned char *result)
{
	int	j;

	j = *i;
	while(format[j] != '%' && format[j] != '\0')
		j++;
	j = j - *i;
	result = (unsigned char *)ft_strnextend((char *)result, (format + *i), j);
	*i = *i + j;
	return (result);
}	

int		ft_printf(char *format, ...)
{
	va_list			ap;
	unsigned char	*result;
	int				i;
	int				ret;

	i = 0;
	ret = 0;
	result = (unsigned char *)ft_strnew(0);
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if(format[i] != '%')
		{
			result = ft_ordinary_management(format, &i, result);
		}
		else
		{
			result = ft_conv_management(format, &i, &ap, result);
		}
	}
	va_end(ap);
	ft_putstr((char *)result);
	free(result);
	return (ret);
}

int		main(void)
{
	char	c;
	char	c2;
	char	str[] = "Hello";
	char	str2[] = "You";
/*	char	*str;
	char	*str2;

	str = strdup("Hello");
	str2 = strdup("You"); */
	c = 'A';
	c2 = 'B';

	ft_printf("%c____\n%s____\n%c_\n_\n\n%c\n%c_%c%s_", c, str, c2, c, c2, c, str2);
	return (0);
}
