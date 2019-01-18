/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:05:30 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/18 18:47:40 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_conv_management(char *format, int *i, va_list *ap)
{
	t_conv_spec		conv_spec;
	int				len;
	char			*str;

	ft_struct_init(&conv_spec);
	len = ft_conv_id(&conv_spec, format, *i);
	if (len == 0)
	{
		while (format[*i] != '\0')
			*i = *i + 1;
		return (NULL);
	}
	ft_flag(&conv_spec, format, *i, len);
	ft_modifier(&conv_spec, format, *i, len);
	ft_field_width(&conv_spec, format, *i, len);
	ft_precision(&conv_spec, format, *i, len);
	str = ft_process_id(conv_spec, ap);
	str = ft_process_preci(conv_spec, str);
	str = ft_process_min_width(conv_spec, str);
	str = ft_process_flags(conv_spec, str);
	*i = *i + len + 1;
	ft_struct_del(&conv_spec);
	return (str);
}

char			*ft_ordinary_management(char *format, int *i)
{
	int		j;
	char	*str;

	j = *i;
	while (format[j] != '%' && format[j] != '\0')
		j++;
	j = j - *i;
	str = ft_strsub(format, *i, j);
	*i = *i + j;
	return (str);
}

char			*ft_prepare_result(char *format, va_list *ap)
{
	char	*result;
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	result = ft_strnew(0);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			tmp = ft_ordinary_management(format, &i);
		else if (!(tmp = ft_conv_management(format, &i, ap)))
			break ;
		if (!(result = ft_strextend(result, tmp)))
			return (0);
		if (tmp != NULL)
		{
			free(tmp);
			tmp = NULL;
		}
	}
	return (result);
}

int				ft_printf(char *format, ...)
{
	va_list			ap;
	char			*result;
	int				ret;

	ret = 0;
	va_start(ap, format);
	result = ft_prepare_result(format, &ap);
	ret = (int)ft_strlen(result);
	ft_char_replace(result, -1, 0);
	write(1, result, ret);
	if (result)
		free(result);
	va_end(ap);
	return (ret);
}
