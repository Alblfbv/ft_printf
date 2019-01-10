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

	max = 3;

	table[0].conv_id = 'c';
	table[0].fptr = &ft_process_c;

	table[1].conv_id = 's';
	table[1].fptr = &ft_process_s;
	
	table[2].conv_id = 'p';
	table[2].fptr = &ft_process_p;

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
