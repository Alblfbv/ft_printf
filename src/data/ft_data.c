/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:59:37 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/10 16:17:05 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

char	*ft_data_conv_ids(void)
{
	char	*conv_ids;

	conv_ids = ft_memalloc(CONV_ID_NB + 1);
	conv_ids[0] = 'd';
	conv_ids[1] = 'i';
	conv_ids[2] = 'o';
	conv_ids[3] = 'u';
	conv_ids[4] = 'x';
	conv_ids[5] = 'X';
	conv_ids[6] = 'c';
	conv_ids[7] = 's';
	conv_ids[8] = 'p';
	conv_ids[9] = 'f';
	conv_ids[10] = '\0';
	return (conv_ids);
}

/*char	**ft_data_type(void)
{
	char	**types;

	type = ft_memalloc(10);
	type[0] = ft_strdup("char");
	type[1] = ft_strdup("unsigned char");
	type[2] = ft_strdup("short");
	type[3] = ft_strdup("unsigned short");
	type[4] = ft_strdup("int");
	type[5] = ft_strdup("unsigned int");
	type[6] = ft_strdup("long");
	type[7] = ft_strdup("unsigned long");
	type[8] = ft_strdup("long long");
	type[9] = ft_strdup("unsigned long long");

	return (types);
}*/
