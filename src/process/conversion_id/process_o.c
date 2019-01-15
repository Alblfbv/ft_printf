/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:53:58 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/15 15:20:16 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_o(t_conv_spec conv_spec, va_list *ap)
{
	char	*str;
	char	*str2;

	str = ft_itoa_base(va_arg(*ap, unsigned int), 8);
	return (str);
}
