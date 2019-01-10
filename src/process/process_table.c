/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:13:32 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/10 16:19:25 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

int		ft_init_table(t_fptr *table)
{
	int		max;
	int		i;
	char	*tab;
	char	*(*fptr[5])(t_conv_spec, va_list*); 
	
	i = 0;
	max = 5;
	tab = ft_strdup("cspdi");
	fptr[0] = ft_process_c;
	fptr[1] = ft_process_s; 
	fptr[2] = ft_process_p;
	fptr[3] = ft_process_di;
	fptr[4] = ft_process_di;
	while (i < max)
	{
		table[i].conv_id = tab[i];
		table[i].fptr = fptr[i];
		i++;
	}
	return (max);
}

char	*ft_process_table(t_conv_spec conv_spec, va_list *ap)
{
	t_fptr	*table;
	char	*str;
	int		i;
	int		max;

	i = 0;
	table = ft_memalloc(sizeof(table) * CONV_ID_NB);
	max = ft_init_table(table);
	while (i < max)
	{
		if (conv_spec.conv_id == table[i].conv_id)
			str = table[i].fptr(conv_spec, ap);
		i++;
	}
	free(table);
	return (str);
}
