/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:02:58 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/14 19:06:33 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_c(t_conv_spec conv_spec, va_list *ap)
{
	unsigned char	c;
	char	*str;

	c = (unsigned char)va_arg(*ap, int);
	str = ft_strnew(1);
	str[0] = (char)c;
	printf("%d", conv_spec.flags[1]);
	return (str);
}
