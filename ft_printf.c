/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 11:27:25 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/03 16:15:09 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	while (*format)
	{
		
	}
	va_end(ap);
}

int		main(int ac, char **av)
{
	printf("%s\n", av[1]);
	ft_printf("%s\n", av[1]);
}
