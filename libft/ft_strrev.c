/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:12:12 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/09 17:13:47 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	stra;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(str);
	end--;
	while (start < end)
	{
		stra = str[end];
		str[end] = str[start];
		str[start] = stra;
		start++;
		end--;
	}
	return (str);
}
