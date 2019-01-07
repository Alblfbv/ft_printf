/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_stock.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:06:10 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/07 18:42:33 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conv_id(t_conv_spec *conv_spec, char *format, int i)
{
	char	*conv_ids;
	int		j;
	int		tmp;
	int		len;

	conv_ids = ft_data_conv_ids();
	tmp = ft_strlen(conv_ids) - 1;
	len = i;
	while (format[i] != '\0')
	{
		j = tmp;
		while (j >= 0)
		{
			if (conv_ids[j] == format[i])
			{
				conv_spec->conv_id = conv_ids[j];
				free(conv_ids);
				return (i - len);
			}
			j--;
		}
		i++;
	}
	free(conv_ids);
	return (0);
}

void	ft_param_value(t_conv_spec *conv_spec, va_list *ap)
{
	if (conv_spec->conv_id == 'd' || conv_spec->conv_id == 'i' ||
		conv_spec->conv_id == 'c')
		conv_spec->param_value_int = va_arg(*ap, int);
	
	if (conv_spec->conv_id == 'o' || conv_spec->conv_id == 'u' ||
		conv_spec->conv_id == 'x' || conv_spec->conv_id == 'X')
		conv_spec->param_value_u_int = va_arg(*ap, unsigned int);
	
	if (conv_spec->conv_id == 'f')
		conv_spec->param_value_double = va_arg(*ap, double);
	
	if (conv_spec->conv_id == 's')
		conv_spec->param_value_char = (char*)va_arg(*ap, const char*);
	
	if (conv_spec->conv_id == 'p')
		conv_spec->param_value_void = va_arg(*ap, void*);
}


void	ft_flag(t_conv_spec *conv_spec, char *format, int i, int len)
{
	int		*tab_flags;

	tab_flags = ft_memalloc(4);
	tab_flags[0] = 0;
	tab_flags[1] = 0;
	tab_flags[2] = 0;
	tab_flags[3] = 0;
	if ((ft_strnchr(format + i, '#', len)) != NULL)
		tab_flags[0] = 1;
	if ((ft_strnchr(format + i, '0', len)) != NULL)
		tab_flags[1] = 1;
	if ((ft_strnchr(format + i, '-', len)) != NULL)
		tab_flags[2] = 1;
	if ((ft_strnchr(format + i, '+', len)) != NULL)
		tab_flags[3] = 1;
	conv_spec->flags = tab_flags;
	free(tab_flags);
}
