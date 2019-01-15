/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:22:29 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/15 16:29:06 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		ft_check_result(t_base_ll stock)
{
	unsigned long long		i;

	i = 0;
	while (stock.tab[i] != '\0')
	{
		if ((int)stock.result + 48 == stock.tab[i])
			return (stock.tab[i]);
		if (((int)stock.result + 87) == stock.tab[i])
			return (stock.tab[i]);
		i++;
	}
	return (0);
}

static char		*ft_cal(t_base_ll *stock, unsigned long long  base, char *str)
{
	stock->c = ft_strnew(1);
	stock->quotien = stock->value / base;
	stock->result = stock->value - (stock->quotien * base);
	stock->c[0] = ft_check_result(*stock);
	str = ft_strextend(str, stock->c);
	free(stock->c);
	return (str);
}

char			*ft_itoa_base_ll(unsigned long long  n, unsigned long long base)
{
	char			*str;
	t_base_ll		stock;

	if (base < 2 && base > 16)
		return (NULL);
	stock.tab = ft_strdup("0123456789abcdef");
	stock.value = n;
	stock.div = stock.value;
	stock.num_div = 0;
	while (stock.div > base)
	{
		stock.div = stock.div / base;
		stock.num_div++;	
	}
	str = ft_strnew(stock.num_div + 1);
	while (stock.value >= base)
	{
		str = ft_cal(&stock, base, str);
		stock.value = stock.value / base;
	}
	str = ft_cal(&stock, base, str);
	str = ft_strrev(str);
	free(stock.tab);
	return (str);
}
