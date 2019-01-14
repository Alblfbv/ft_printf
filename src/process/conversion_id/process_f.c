/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:30:04 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/14 18:35:21 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_f(t_conv_spec conv_spec, va_list *ap)
{
	char	*str;
	double	nb;

	nb = va_arg(*ap, double);
	
	return (str);
}

