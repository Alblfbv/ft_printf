/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:30:04 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/17 15:14:43 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_process_f(t_conv_spec conv_spec, va_list *ap)
{
	if (conv_spec.modifier[4] == 1)
		return (ft_itoa_double_l(conv_spec, va_arg(*ap, long double)));
	else
		return (ft_itoa_double(conv_spec, va_arg(*ap, double)));
}
