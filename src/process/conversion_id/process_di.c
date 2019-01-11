/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:02:37 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/10 18:38:58 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_di(t_conv_spec conv_spec, va_list *ap)
{
	char	*str;

	str = ft_itoa(va_arg(*ap, int));
	ft_process_flags(conv_spec, str);
	return (str);
}
