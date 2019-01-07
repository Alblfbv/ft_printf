/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:53:03 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/07 18:19:13 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnchr(const char *s, int c, int n)
{
	while (*s != (char)c && *s != '\0')
	{
		s++;
		n--;
		if (n == 0)
			return (NULL);
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
