/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:49:48 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/14 17:26:23 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision_di(t_conv_spec conv_spec, char *str)
{
	int		i;
	int		j;
	char	*str2;

	i = ft_strlen(str);
	if (i < conv_spec.precision)
	{
		j = conv_spec.precision - i;
		str2 = ft_strnew(j);
		ft_memset(str2, '0', j);
		str2 = ft_strextend(str2, str);
		free(str);
		return (str2);
	}
	return (str);
}
