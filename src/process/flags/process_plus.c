/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:55:16 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/11 17:55:32 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_plus(t_conv_spec conv_spec, char *str)
{
	int		i;
	char	*end;
	char	*start;

	i = 0;
								//	printf("ft_process_plus(): tab_flag + = %d\n", conv_spec.flags[3]);
	while (!(ft_isdigit(str[i])))
			i++;
	start = ft_strsub(str, 0, i);
	end = ft_strsub(str, i, strlen((str + i)));
	free(str);
	str = ft_strextend(start, "+");
	str = ft_strextend(str, end);
//	free(start);
//	free(end);
	return (str);
}
