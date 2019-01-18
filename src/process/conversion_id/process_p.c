/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:10:52 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/18 19:53:47 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_p(t_conv_spec conv_spec, va_list *ap)
{
	char	*str;
	char	*str2;

	(void)conv_spec;
	str = ft_itoa_base(va_arg(*ap, unsigned int), 16);
//	if (str[0] == '0' && str[1] == '\0')
		str2 = ft_strdup("0x");
//	else
//		str2 = ft_strdup("0x7fff");
	str2 = ft_strextend(str2, str);
	free(str);
	return (str2);
}
