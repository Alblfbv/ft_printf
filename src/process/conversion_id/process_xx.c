/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:19:56 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/14 17:31:07 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_X(t_conv_spec conv_spec, va_list *ap)
{
	char	*str;
	
	str = ft_itoa_base(va_arg(*ap, unsigned int), 16);
	str = ft_strupcase(str);
	return (str);
}
