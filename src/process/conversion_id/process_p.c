/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:10:52 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/14 19:06:25 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_p(t_conv_spec conv_spec, va_list *ap)
{
	char	*str;
	char	*str2;

	str = ft_itoa_base(va_arg(*ap, unsigned int), 16);
	str2 = ft_strdup("0xfff7");
	str2 = ft_strextend(str2, str);
	free(str);
	return (str2);
}
