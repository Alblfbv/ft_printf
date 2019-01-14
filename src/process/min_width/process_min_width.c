/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_min_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:42:02 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/14 17:33:39 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_min_width(t_conv_spec conv_spec, char *str)
{
	char	*tmp;
	int		i;

	if (conv_spec.flags[3] == 1)
		i = ft_strlen(str) + 1;
	else
		i = ft_strlen(str);
	if (i < conv_spec.field_width)
	{
		tmp = ft_strnew(conv_spec.field_width - i);
		ft_memset(tmp, ' ', conv_spec.field_width - i);
		tmp = ft_strextend(tmp, str);
		free(str);
		str = tmp;
	}
	return (str);
}
