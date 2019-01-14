/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:30:04 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/14 19:15:59 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_f(t_conv_spec conv_spec, va_list *ap)
{
	char	*str;
	char	*str2;
	int		tmp;
	double	nb;

	nb = 12.369;
	tmp = nb;
	str = ft_itoa(tmp);
	str2 = ft_strdup('.');
	str2 = ft_strextend(str2, str);
	free(str);
	nb = nb - tmp;
	while (conv_spec.precision != 0)
	{
		nb = nb * 10;

	}
	return (str2);
}

