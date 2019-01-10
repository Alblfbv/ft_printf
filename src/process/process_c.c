/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:02:58 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/09 18:27:47 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

char	*ft_process_c(t_conv_spec conv_spec, va_list *ap)
{
	unsigned char	c;
	unsigned char	*str;

	c = (unsigned char)va_arg(*ap, int);
	str = (unsigned char *)ft_strnew(1);
	str[0] = c;
	return ((char *)str);
}
