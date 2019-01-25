/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:36:44 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/25 13:50:13 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_place_point(t_conv_spec conv_spec, char *str)
{
	char	*final_str;
	int		i;

	final_str = ft_strnew(ft_strlen(str) + 1);
	i = ft_strlen(str) - conv_spec.precision;
	ft_strncpy(final_str, str, i);
	final_str[i] = '.';
	ft_strcat(final_str, str + i);
	free(str);
	return (final_str);
}

char		*ft_itoa_double(t_conv_spec conv_spec, long double nb)
{
	unsigned long long		result;
	unsigned long long		tmp;
	unsigned long long		power;
	char					*str;
	int						flag;

	flag = 0;
	if (nb < 0)
	{
		flag = 1;
		nb = -nb;
	}
	if (conv_spec.precision == -1)
		conv_spec.precision = 6;
	power = ft_power(10, conv_spec.precision);
	result = nb * power;
	tmp = nb * power * 10;
	if ((tmp - (result * 10)) > 5)
		result++;
	if (flag == 1)
		result = -result;
	str = ft_itoa(result);
	str = ft_place_point(conv_spec, str);
	return (str);
}
