/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:16:02 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/14 16:56:30 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_zero(t_conv_spec conv_spec, char *str)
{
	int	i;
	char	*tmp;

	if (conv_spec.precision != 0 || conv_spec.flags[2] == 1)
		return (str);
	i = 0;
	while (str[i] == ' ')
	{
		str[i] = '0';
		i++;
	}
	return (str);
}
