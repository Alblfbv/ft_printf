/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:04:24 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/09 18:31:01 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

char	*ft_process_s(t_conv_spec conv_spec, va_list *ap)
{
	char	*s;

	s = va_arg(*ap, char*);
	return (s);
}
