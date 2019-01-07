/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 11:26:18 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/07 15:39:58 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONV_ID_NB 10

typedef struct	s_conv_spec
{
	char	conv_id;
	char	*type;
	char	*flag;
	char	*field_width_base;
	char	*precision_base;
	char	*length_modifier;

	int		field_width_final;
	int		precision_final;

	char*	converted;
}					t_conv_spec;

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

char	*ft_data_conv_ids(void);
void	ft_conv_id(t_conv_spec *conv_spec, char *format, int i);

#endif
