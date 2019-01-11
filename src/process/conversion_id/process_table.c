/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:13:32 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/11 15:05:11 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_init_table(t_fptr_id *table)
{
	int	max;

	max = 5;
	table->conv_id_tab = ft_strdup("cspdi");
	table->fptr[0] = ft_process_c;
	table->fptr[1] = ft_process_s;
	table->fptr[2] = ft_process_p;
	table->fptr[3] = ft_process_di;
	table->fptr[4] = ft_process_di;
	return (max);
}

char		*ft_process_table(t_conv_spec conv_spec, va_list *ap)
{
	t_fptr_id	*table;
	char		*str;
	int			i;
	int			max;

	i = 0;
	table = ft_memalloc(sizeof(table) * CONV_ID_NB);
	max = ft_init_table(table);
	while (i < max)
	{
		if (conv_spec.conv_id == table->conv_id_tab[i])
			str = table->fptr[i](conv_spec, ap);
		i++;
	}
	free(table);
	return (str);
}
