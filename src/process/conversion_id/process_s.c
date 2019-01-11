/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:04:24 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/10 16:25:09 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_s(t_conv_spec conv_spec, va_list *ap)
{
	char	*s;
	char	*s2;

	s = va_arg(*ap, char*);
	s2 = ft_strdup(s);
	return (s2);
}
