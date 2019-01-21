/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:16:02 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/21 15:40:33 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_zero(t_conv_spec conv_spec, char *str)
{
	int		i;
	char	*tmp;

	if ((conv_spec.precision != -1 && (conv_spec.conv_id != 'c' && conv_spec.conv_id != 's' && conv_spec.conv_id != '%'))
		|| conv_spec.flags[4] == 1 || conv_spec.conv_id == 'p')
		return (str);
	i = 0;
	if (conv_spec.flags[1] == 1 && conv_spec.flags[0] == -1 &&
		(conv_spec.conv_id == 'd' || conv_spec.conv_id == 'i') && str[i] != '-')
		i++;
	while (str[i] == ' ')
	{
		str[i] = '0';
		i++;
	}
	if (((ft_strchr(str, '+')) || (ft_strchr(str, '-'))) && i != 0)
	{
		tmp = ft_strnew(ft_strlen(str));
		ft_strncpy(tmp, str + i, 1);
		ft_strncat(tmp, str, i);
		ft_strcat(tmp, str + i + 1);
		free(str);
		str = tmp;
	}
	return (str);
}
