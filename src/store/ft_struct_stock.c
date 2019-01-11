/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_stock.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:06:10 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/10 16:42:42 by allefebv         ###   ########.fr       */
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

void	ft_size_modif(t_conv_spec *conv_spec, char *format, int i, int len)
{
	conv_spec->size_modif = (int *)ft_memalloc(sizeof(int) * 5);
	conv_spec->size_modif[0] = 0;
	conv_spec->size_modif[1] = 0;
	conv_spec->size_modif[2] = 0;
	conv_spec->size_modif[3] = 0;
	conv_spec->size_modif[4] = 0;
	while (len > 0)
	{
		if (format[i] == 'h' && format[i + 1] != 'h' && format[i - 1] != 'h')
			conv_spec->size_modif[0] = 1;
		if (format[i] == 'h' && format[i + 1] == 'h')
			conv_spec->size_modif[1] = 1;
		if (format[i] == 'l' && format[i + 1] != 'l' && format[i - 1] != 'l')
			conv_spec->size_modif[2] = 1;
		if (format[i] == 'l' && format[i + 1] == 'l')
			conv_spec->size_modif[3] = 1;
		if (format[i] == 'L')
			conv_spec->size_modif[4] = 1;
		i++;
		len--;
	}
}

void	ft_flag(t_conv_spec *conv_spec, char *format, int i, int len)
{
	int		*tab_flags;

	tab_flags = (int *)ft_memalloc(sizeof(int) * 4);
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

void    ft_precision(t_conv_spec *conv_spec, char *format, int i, int len)
{
	conv_spec->precision = 0;
	while (len > 0)
	{
		if (format[i] == '.')
		{
			i++;
			len--;
			while (format[i] >= '0' && format[i] <= '9')
			{
				conv_spec->precision = (conv_spec->precision * 10) + (format[i] - 48);
				i++;
				len--;
			}
			return ;
		}
		i++;
		len--;
	}
}
