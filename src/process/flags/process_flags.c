/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:02:32 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/11 17:58:08 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_init_table(t_fptr_flag *table)
{
	int		max;
	int		i;

	i = 0;
	max = 4;
//	table->flags = ft_memalloc(sizeof(int) * max);
//	table->fptr = ft_memalloc(sizeof(table->fptr) * FLAGS_NB);
	while (i < max)
	{
		table[i].flags = 1;
		i++;
	}
	table[0].fptr = &ft_process_hash;
	table[1].fptr = &ft_process_zero;
	//table->fptr[2] = &ft_process_minus;
	table[3].fptr = &ft_process_plus;
	return (max);
}

char		*ft_process_flags(t_conv_spec conv_spec, char *str)
{
	t_fptr_flag		*table;
	int				i;
	int				max;

	i = 0;
	table = ft_memalloc(sizeof(*table) * FLAGS_NB);
	max = ft_init_table(table);
					//	printf("ft_process_flags(): conv_spec_flags : %d %d %d %d\n", conv_spec.flags[0], conv_spec.flags[1], conv_spec.flags[2], conv_spec.flags[3]);
					//	printf("ft_process_flags(): table_flags : %d %d %d %d\n", table->flags[0], table->flags[1], table->flags[2], table->flags[3]);
	while (i < max)
	{
					//	printf("ft_process_flags(): Table_flag[%d] : %d conv_spec_flag[%d] : %d\n", i, table->flags[i], i, conv_spec.flags[i]);
		if (conv_spec.flags[i] == table[i].flags)
			str = table[i].fptr(conv_spec, str);
		i++;
	}
	free(table);
	return (str);
}
