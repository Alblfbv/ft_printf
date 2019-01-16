/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:49:48 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/16 17:34:23 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision_diouxx(t_conv_spec conv_spec, char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = ft_strlen(str);
	if (conv_spec.precision == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	if (i < conv_spec.precision)
	{
		j = conv_spec.precision - i;
		tmp = ft_strnew(j);
		ft_memset(tmp, '0', j);
		tmp = ft_strextend(tmp, str);
		free(str);
		str = tmp;
	}
	return (str);
}
