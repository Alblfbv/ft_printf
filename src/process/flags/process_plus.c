/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:55:16 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/11 14:26:57 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_process_plus(t_conv_spec conv_spec, char *str)
{
	int		i;
	char	*end;
	char	*start;

	i = 0;
	while (!(ft_isdigit(str[i]))
			i++;
	start = ft_strsub(str, 0, i);
	end = ft_strsub(str, i, strlen((str + i)));
	free(str);
	str = ft_strextend(start, "+");
	str = ft_strextend(str, end);
	free(start);
	free(end);
	return (str);
}
