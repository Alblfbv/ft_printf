/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:19:56 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/14 18:40:38 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_x(t_conv_spec conv_spec, va_list *ap)
{
	char	*str;
	char	*str2;
	
	str = ft_itoa_base(va_arg(*ap, unsigned int), 16);
	if (conv_spec.flags[0] == 1)
	{
		str2 = ft_strdup("0x");
		str2 = ft_strextend(str2, str);
		free(str);
		return (str2);
	}
	return (str);
}
