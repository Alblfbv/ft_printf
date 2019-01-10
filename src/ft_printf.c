/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:05:30 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/09 19:45:42 by allefebv         ###   ########.fr       */
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
	//ft_flag(conv_spec, format, *i, len);
	//ft_size_modif(conv_spec, format, *i, len);
	//ft_field_width(conv_spec, format, *i, len);
	//ft_precision(conv_spec, format, *i, len);
	return (len);
}

char	*ft_conv_management(char *format, int *i, va_list *ap, char *result)
{
	t_conv_spec		conv_spec;
	int				len;

	//ft_struct_init(&conv_spec);
	len = ft_struct_create(&conv_spec, format, i);
//	printf("Format[i] = %c\nlen = %d\n", format[*i], len);
//	printf("conv_id = %c\n", conv_spec.conv_id);
	result = ft_strextend(result, ft_conv_process(conv_spec, ap));
//	printf("After ConvMana : %s\n", result);
	*i = *i + len + 1;
	//ft_struct_del(&conv_spec);
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
		{
			result = ft_ordinary_management(format, &i, result);
//			printf("After Ordinary dans principal: %s\n", result);
		}
		else
		{
//			printf("Before Conv dans principal: %s\n", result);
			result = ft_conv_management(format, &i, &ap, result);
//			printf("After Conv dans principal: %s\n", result);
		}
	}
	va_end(ap);
	free(result);
	return (ret);
}

int		main(void)
{
	int		a;

	ft_printf("%p", &a);
	return (0);
}
