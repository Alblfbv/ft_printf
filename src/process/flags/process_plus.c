/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:55:16 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/14 18:21:58 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_plus(t_conv_spec conv_spec, char *str)
{
	int		i;
	char	*end;
	char	*start;

	i = 0;
	if (conv_spec.conv_id == 'd' || conv_spec.conv_id == 'i')
	{
		while (!(ft_isdigit(str[i])) && str[i] != '\0')
				i++;
		if (str[i] == '\0')
			return (str);
		start = ft_strsub(str, 0, i);
		end = ft_strsub(str, i, ft_strlen((str + i)));
		free(str);
		str = ft_strnew(ft_strlen(start) + ft_strlen(end) + 1);
		ft_strcpy(str, start);
		ft_strcat(str, "+");
		ft_strcat(str, end);
		free(end);
		free(start);
	}
	return (str);
}
