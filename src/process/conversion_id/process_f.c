/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:30:04 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/17 13:49:13 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_cal_rounded(t_conv_spec conv_spec, char *final_str,
				double *nb, int flag)
{
	int		result;
	int		tmp;
	char	*str;

	*nb = *nb * 10;
	result = *nb;
	result = result % 10;
	*nb = *nb * 10;
	tmp = *nb;
	tmp = tmp % 10;
	if (tmp > 5)
		result++;
	str = ft_strnew(1);
	str[0] = result + 48;
	final_str = ft_strextend(final_str, str);
	free(str);
	if (flag == 1)
		conv_spec.precision = -1;
	return (final_str);
}

static int		ft_cal_nb(double *nb)
{
	int		result;

	*nb = *nb * 10;
	result = *nb;
	result = result % 10;
	return (result);
}

static char		*ft_while_process(t_conv_spec *conv_spec, char *str,
									char *fs, double *nb)
{
	str = ft_strnew(1);
	str[0] = ft_cal_nb(nb) + 48;
	fs = ft_strextend(fs, str);
	free(str);
	conv_spec->precision--;
	return (fs);
}

char			*ft_process_f(t_conv_spec conv_spec, va_list *ap)
{
	char	*str;
	char	*final_str;
	int		tmp;
	double	nb;
	int		flag;

	flag = 0;
	nb = va_arg(*ap, double);
	tmp = nb;
	final_str = ft_itoa(tmp);
	str = ft_strdup(".");
	final_str = ft_strextend(final_str, str);
	free(str);
	nb = nb - tmp;
	if (conv_spec.precision == -1)
	{
		conv_spec.precision = 6;
		flag = 1;
	}
	while (conv_spec.precision > 1)
		final_str = ft_while_process(&conv_spec, str, final_str, &nb);
	final_str = ft_cal_rounded(conv_spec, final_str, &nb, flag);
	return (final_str);
}
