/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:13:32 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/11 17:48:00 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_init_table(t_fptr_id *table)
{
	int		max;
	int		i;
	char	*tab;
	char	*(*fptr[5])(t_conv_spec, va_list*); 
	max = 5;
	i = 0;
//	table->fptr = ft_memalloc(sizeof(table->fptr) * CONV_ID_NB);
	tab = ft_strdup("cspdi");
	fptr[0] = ft_process_c;
	fptr[1] = ft_process_s; 
	fptr[2] = ft_process_p;
	fptr[3] = ft_process_di;
	fptr[4] = ft_process_di;
	while (i < max)
	{
		table[i].conv_id_tab = tab[i];
		table[i].fptr = fptr[i];
		i++;
	}
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
		if (conv_spec.conv_id == table[i].conv_id_tab)
			str = table[i].fptr(conv_spec, ap);
		i++;
	}
	free(table);
	return (str);
}
