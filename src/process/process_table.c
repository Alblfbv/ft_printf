/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:13:32 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/09 18:20:02 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	ft_init_table(t_fptr *table)
{
	table[0].conv_id = 'c';
	table[0].fptr = &ft_process_c;

	table[1].conv_id = 's';
	table[1].fptr = &ft_process_s;
}

char	*ft_process_table(t_conv_spec conv_spec, va_list *ap)
{
	t_fptr	*table;
	char	*str;
	int		i;

	i = 0;
	table = ft_memalloc(sizeof(table) * CONV_ID_NB);
	ft_init_table(table);
	while (i < CONV_ID_NB)
	{
		if (conv_spec.conv_id == table[i].conv_id)
			str = table[i].fptr(conv_spec, ap);
		i++;
	}
	return (str);
}
