/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:53:58 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/14 19:17:59 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_o(t_conv_spec conv_spec, va_list *ap)
{
	char	*str;
	char	*str2;

	str = ft_itoa_base(va_arg(*ap, unsigned int), 8);
	if (conv_spec.flags[0] == 1)
	{
		str2 = ft_strdup("0");
		str2 = ft_strextend(str2, str);
		free(str);
		return (str2);
	}
	return (str);
}
