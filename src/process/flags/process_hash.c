/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:00:04 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/16 14:05:56 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_add(char *str, char *to_add, int i)
{
	char	*end;
	char	*start;

	start = ft_strsub(str, 0, i);
	end = ft_strsub(str, i, ft_strlen((str + i)));
	free(str);
	str = ft_strnew(ft_strlen(start) + ft_strlen(end) + ft_strlen(to_add));
	ft_strcpy(str, start);
	ft_strcat(str, to_add);
	ft_strcat(str, end);
	free(end);
	free(start);
	return (str);
}

static char	*ft_x(char *str, int i)
{
	char	*to_add;

	if (i > 1)
	{
		str[i - 1] = 'x';
		str[i - 2] = '0';
	}
	else if (i == 1)
	{
		str[i - 1] = 'x';
		to_add = ft_strdup("0");
		i--;
		str = ft_add(str, to_add, i);
	}
	else
	{
		to_add = ft_strdup("0x");
		str = ft_add(str, to_add, i);
	}
	return (str);
}

static char	*ft_xx(char *str, int i)
{
	char	*to_add;

	if (i > 1)
	{
		str[i - 1] = 'X';
		str[i - 2] = '0';
	}
	else if (i == 1)
	{
		str[i - 1] = 'X';
		to_add = ft_strdup("0");
		i--;
		str = ft_add(str, to_add, i);
	}
	else
	{
		to_add = ft_strdup("0X");
		str = ft_add(str, to_add, i);
	}
	return (str);
}

static char	*ft_o(char *str, int i)
{
	char	*to_add;

	if (i > 0)
		str[i - 1] = '0';
	else
	{
		to_add = ft_strdup("0");
		str = ft_add(str, to_add, i);
	}
	return (str);
}

char		*ft_process_hash(t_conv_spec conv_spec, char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	if (conv_spec.conv_id == 'x')
		str = ft_x(str, i);
	else if (conv_spec.conv_id == 'X')
		str = ft_xx(str, i);
	else if (conv_spec.conv_id == 'o')
		str = ft_o(str, i);
	return (str);
}
