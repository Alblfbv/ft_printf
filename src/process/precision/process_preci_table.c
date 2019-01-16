/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_preci_table.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:24:14 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/16 14:36:50 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_table(t_fptr_preci *table)
{
	table->preci_group = ft_memalloc(sizeof(char*) * (PRECI_GROUPS + 1));
	table->preci_group[0] = ft_strdup("s");
	table->preci_group[1] = ft_strdup("diouxX");
	table->preci_group[PRECI_GROUPS] = 0;
	table->fptr[0] = &ft_precision_s;
	table->fptr[1] = &ft_precision_diouxx;
}

char		*ft_process_preci(t_conv_spec conv_spec, char *str)
{
	t_fptr_preci	*table;
	int				i;

	if (conv_spec.precision != -1)
	{
		i = 0;
		table = ft_memalloc(sizeof(*table));
		ft_init_table(table);
		while (i < PRECI_GROUPS)
		{
			if (ft_strchr(table->preci_group[i], conv_spec.conv_id))
				str = table->fptr[i](conv_spec, str);
			i++;
		}
		i--;
		while (i >= 0)
		{
			free(table->preci_group[i]);
			i--;
		}
		free(table->preci_group);
		free(table);
	}
	return (str);
}
