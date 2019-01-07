/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_stock.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:06:10 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/07 15:44:30 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conv_id(t_conv_spec *conv_spec, char *format, int i)
{
	char	*conv_ids;
	int		j;
	int		tmp;

	conv_ids = ft_strdup(ft_data_conv_ids());
	tmp = ft_strlen(conv_ids) - 1;
	while (format[i] != '\0')
	{
		j = tmp;
		while (j >= 0)
		{
			if (conv_ids[j] == format[i])
			{
				conv_spec->conv_id = conv_ids[j];
				return ;
			}
			j--;
		}
		i++;
	}
}
