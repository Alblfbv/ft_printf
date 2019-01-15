/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:13:32 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/15 15:28:11 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static int	ft_init_table(t_fptr_id *table)
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
}*/

static void	ft_init_table(t_fptr_id *table)
{
	table->conv_id_tab = ft_strdup("cspdiouxXf");
	table->fptr[0] = ft_process_c;
	table->fptr[1] = ft_process_s; 
	table->fptr[2] = ft_process_p;
	table->fptr[3] = ft_process_di;
	table->fptr[4] = ft_process_di;
	table->fptr[5] = ft_process_o;
	table->fptr[6] = ft_process_u;
	table->fptr[7] = ft_process_x;
	table->fptr[8] = ft_process_X;
	table->fptr[9] = ft_process_f;
}

char		*ft_process_id(t_conv_spec conv_spec, va_list *ap)
{
	t_fptr_id	*table;
	char		*str;
	int			i;

	i = 0;
	table = ft_memalloc(sizeof(*table));
	ft_init_table(table);
	while (i < CONV_ID_NB)
	{
		if (conv_spec.conv_id == table->conv_id_tab[i])
			str = table->fptr[i](conv_spec, ap);
		i++;
	}
	free(table->conv_id_tab);
	free(table);
	return (str);
}
