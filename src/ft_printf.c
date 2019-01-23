/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:05:30 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/23 13:32:21 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_store_conv(char *ft, int *i, t_conv_spec *conv_spec, va_list *ap)
{
	int				len;
	char			*tmp;

	len = ft_conv_id(conv_spec, ft, *i);
	if (len == 0)
	{
		while (ft[*i] != '\0')
			*i = *i + 1;
		return (len);
	}
	ft_flag(conv_spec, ft, *i, len);
	ft_modifier(conv_spec, ft, *i, len);
	if ((tmp = ft_strnchr((ft + *i), '*', len)) != NULL && *(tmp - 1) != '.')
		ft_wc_field_width(conv_spec, ap);
	else
		ft_field_width(conv_spec, ft, *i, len);
	if ((tmp = ft_strrnchr((ft + *i), '*', len)) != NULL && *(tmp - 1) == '.')
		ft_wc_precision(conv_spec, ap);
	else
		ft_precision(conv_spec, ft, *i, len);
	return (len);
}

char	*ft_conv_management(char *format, int *i, va_list *ap)
{
	t_conv_spec		conv_spec;
	int				len;
	char			*str;

	ft_struct_init(&conv_spec);
	if ((len = ft_store_conv(format, i, &conv_spec, ap)) == 0)
		return (NULL);
	str = ft_process_id(conv_spec, ap);
	str = ft_process_preci(conv_spec, str);
	str = ft_process_min_width(conv_spec, str);
	str = ft_process_flags(conv_spec, str);
	*i = *i + len + 1;
	ft_struct_del(&conv_spec);
	return (str);
}

char	*ft_ordinary_management(char *format, int *i)
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

char	*ft_prepare_result(char *format, va_list *ap)
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

int		ft_printf(char *format, ...)
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
