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

/*void	ft_conversion(t_conv_spec conv_spec, char *result)
{

}*/

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

char	*ft_conv_management(char *format, int *i, va_list *ap, char *result)
{
	t_conv_spec		conv_spec;
	int				len;
	len = ft_struct_create(&conv_spec, format, i, ap);
	//ft_conversion(conv_spec, result);
	*i = *i + len + 1;
	return (result);
}

char	*ft_ordinary_management(char *format, int *i, char *result)
{
	int	j;

	j = *i;
	while(format[j] != '%' && format[j] != '\0')
		j++;
	j = j - *i;
	result = ft_strnextend(result, (format + *i), j);
	*i = *i + j;
	return (result);
}

int		ft_printf(char *format, ...)
{
	va_list	ap;
	char	*result;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	result = ft_strnew(0);
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if(format[i] != '%')
			result = ft_ordinary_management(format, &i, result);
		else
			result = ft_conv_management(format, &i, &ap, result);
	}
	va_end(ap);
	free(result);
	return (ret);
}

int		main(void)
{
	ft_printf("Hello-%s-%d-world", "the", 10);
	return (0);
}
