/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:02:37 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/15 16:31:16 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_di(t_conv_spec conv_spec, va_list *ap)
{
	if (conv_spec.modifier[0] == 1)
		return (ft_itoa((int)va_arg(*ap, char));
	if (conv_spec.modifier[1] == 1)
		return (ft_itoa((int)va_arg(*ap, short));
	if (conv_spec.modifier[2] == 1)
		return (ft_itoa_ll((long long)va_arg(*ap, long));
	if (conv_spec.modifier[3] == 1)
		return (ft_itoa_ll((long long)va_arg(*ap, long long));
	return (ft_itoa(*ap, int));
}
