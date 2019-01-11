/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:10:52 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/10 15:53:08 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

char	ft_check_result(t_hexa stock)
{
	int		i;

	i = 0;
	while (stock.tab[i] != '\0')
	{
		if (stock.result + 48 == stock.tab[i])
			return (stock.tab[i]);
		if ((stock.result + 87) == stock.tab[i])
			return (stock.tab[i]);
		i++;
	}
	return (0);
}

char	*ft_cal(t_hexa *stock, int value, int base, char *str)
{
	stock->c = ft_strnew(1);
	stock->quotien = value / base;
	stock->result = value - (stock->quotien * base);
	stock->c[0] = ft_check_result(*stock);
	str = ft_strextend(str, stock->c);
	free(stock->c);
	return (str);
}

char	*ft_process_p(t_conv_spec conv_spec, va_list *ap)
{
	t_hexa	stock;
	char	*str;
	int		base;
	int		value;

	value = va_arg(*ap, int);
	base = 16;
	stock.tab = ft_strdup("0123456789abcdef");
	stock.div = value;
	while (stock.div > base)
	{
		stock.div = stock.div / base;
		stock.num_div++;
	}
	str = ft_strnew(stock.num_div + 1);
	while (value >= base)
	{
		str = ft_cal(&stock, value, base, str);
		value = value / base;
	}
	str = ft_cal(&stock, value, base, str);
	str = ft_strextend(str, ft_strdup("fff7x0"));
	str = ft_strrev(str);
	free(stock.tab);
	return (str);
}
