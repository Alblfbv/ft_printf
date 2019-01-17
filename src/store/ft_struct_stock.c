/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_stock.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:06:10 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/16 20:20:26 by jfleury          ###   ########.fr       */
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
		i++;
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
	}
	free(conv_ids);
	return (0);
}

void	ft_modifier(t_conv_spec *conv_spec, char *format, int i, int len)
{
	conv_spec->modifier = (int *)ft_memalloc(sizeof(int) * 5);
	conv_spec->modifier[0] = 0;
	conv_spec->modifier[1] = 0;
	conv_spec->modifier[2] = 0;
	conv_spec->modifier[3] = 0;
	conv_spec->modifier[4] = 0;
	while (len > 0)
	{
		if (format[i] == 'h' && format[i + 1] == 'h')
			conv_spec->modifier[0] = 1;
		if (format[i] == 'h' && format[i + 1] != 'h' && format[i - 1] != 'h')
			conv_spec->modifier[1] = 1;
		if (format[i] == 'l' && format[i + 1] != 'l' && format[i - 1] != 'l')
			conv_spec->modifier[2] = 1;
		if (format[i] == 'l' && format[i + 1] == 'l')
			conv_spec->modifier[3] = 1;
		if (format[i] == 'L')
			conv_spec->modifier[4] = 1;
		i++;
		len--;
	}
}

void	ft_flag(t_conv_spec *conv_spec, char *format, int i, int len)
{
	int		j;
	int		x;

	j = 0;
	conv_spec->flags = (int *)ft_memalloc(sizeof(int) * FLAGS_NB);
	while (j < FLAGS_NB)
	{
		conv_spec->flags[j] = -1;
		j++;
	}
	j = i;
	x = j + len;
	if ((ft_strnchr(format + i, '+', len)) != NULL)
		conv_spec->flags[0] = 1;
	if ((ft_strnchr(format + i, ' ', len)) != NULL)
		conv_spec->flags[1] = 1;
	if ((ft_strnchr(format + i, '#', len)) != NULL)
		conv_spec->flags[2] = 1;
	while (!(ft_isdigit(format[j])) && j < x)
		j++;
	if (format[j] == '0')
		conv_spec->flags[3] = 1;
	if ((ft_strnchr(format + i, '-', len)) != NULL)
		conv_spec->flags[4] = 1;
}

void	ft_precision(t_conv_spec *conv_spec, char *format, int i, int len)
{
	while (len > 0)
	{
		if (format[i] == '.')
		{
			conv_spec->precision = 0;
			i++;
			len--;
			while (format[i] >= '0' && format[i] <= '9')
			{
				conv_spec->precision =
				(conv_spec->precision * 10) + (format[i] - 48);
				i++;
				len--;
			}
			return ;
		}
		i++;
		len--;
	}
}
