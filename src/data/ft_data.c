/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:59:37 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/11 12:12:58 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
