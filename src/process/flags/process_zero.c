/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:16:02 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/16 18:42:26 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_zero(t_conv_spec conv_spec, char *str)
{
	int	i;

	if (conv_spec.precision != -1 || conv_spec.flags[4] == 1
		|| conv_spec.conv_id == 'c' || conv_spec.conv_id == 's'
		|| conv_spec.conv_id == 'p')
		return (str);
	i = 0;
	while (str[i] == ' ')
	{
		str[i] = '0';
		i++;
	}
	return (str);
}
