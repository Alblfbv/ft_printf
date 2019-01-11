/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:02:37 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/11 17:51:48 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_di(t_conv_spec conv_spec, va_list *ap)
{
	char	*str;

	str = ft_itoa(va_arg(*ap, int));
	return (str);
}
