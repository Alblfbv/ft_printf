/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:10:52 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/14 16:30:08 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_p(t_conv_spec conv_spec, va_list *ap)
{
	char	*str;

	str = ft_strdup("0x7fff");
	str = ft_strextend(str, ft_itoa_base(va_arg(*ap, unsigned int), 16));
	return (str);
}
