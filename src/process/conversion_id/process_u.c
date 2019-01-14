/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:18:09 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/14 19:06:22 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_u(t_conv_spec conv_spec, va_list *ap)
{
	char	*str;

	str = ft_itoa_base(va_arg(*ap, unsigned int), 10);
	return (str);
}
