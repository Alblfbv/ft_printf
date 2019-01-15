/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:30:04 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/15 13:51:11 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_cal_nb(t_conv_spec conv_spec, double *nb)
{
	int		result;

	*nb = *nb * 10
	result = nb;
	return (result);
}

char			*ft_process_f(t_conv_spec conv_spec, va_list *ap)
{
	char	*str;
	char	*str2;
	int		tmp;
	double	nb;

	nb = va_arg(*ap, double);
	tmp = nb;
	str = ft_itoa(tmp);
	str2 = ft_strdup(".");
	str2 = ft_strextend(str, str2);
	nb = nb - tmp;
	if (conv_spec.precision = -1)
		conv_spec.precision = 6;
	while (conv_spec.precision > 0)
	{
		tmp = ft_cal_nb(conv_spec, &nb);
		str2 = ft_itoa(tmp);
		str = ft_strextend(str, str2);
	}
	return (str);
}

