/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_hash2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:20:36 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/17 18:39:49 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hash_xx_preci(char *str, int i)
{
	if (i > 1)
	{
		str[i - 2] = '0';
		str[i - 1] = 'X';
	}
	else if (i == 1)
	{
		str[i - 1] = 'X';
		str = ft_strextend(ft_strdup("0"), str);
	}
	else
		str = ft_strextend(ft_strdup("0X"), str);
	return (str);
}

char	*ft_hash_xx_zero(char *str, int i)
{
	if (i > 1)
	{
		str[0] = '0';
		str[1] = 'X';
	}
	else if (i == 1)
	{
		str[1] = 'X';
		str = ft_strextend(ft_strdup("0"), str);
	}
	else
		str = ft_strextend(ft_strdup("0X"), str);
	return (str);
}

char	*ft_hash_x_preci(char *str, int i)
{
	if (i > 1)
	{
		str[i - 2] = '0';
		str[i - 1] = 'x';
	}
	else if (i == 1)
	{
		str[i - 1] = 'x';
		str = ft_strextend(ft_strdup("0"), str);
	}
	else
		str = ft_strextend(ft_strdup("0x"), str);
	return (str);
}

char	*ft_hash_x_zero(char *str, int i)
{
	if (i > 1)
	{
		str[0] = '0';
		str[1] = 'x';
	}
	else if (i == 1)
	{
		str[1] = 'x';
		str = ft_strextend(ft_strdup("0"), str);
	}
	else
		str = ft_strextend(ft_strdup("0x"), str);
	return (str);
}
