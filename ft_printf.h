/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 11:26:18 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/07 18:05:51 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONV_ID_NB 10

typedef struct	s_conv_spec
{
	char				conv_id;
	int					param_value_int;
	unsigned int		param_value_u_int;
	double				param_value_double;
	char 				*param_value_char;
	void				*param_value_void;
	
	int					*flags;
	char				*field_width_base;
	char				*precision_base;
	char				*length_modifier;

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
int		ft_conv_id(t_conv_spec *conv_spec, char *format, int i);
void	ft_param_value(t_conv_spec *conv_spec, va_list *ap);
void	ft_flag(t_conv_spec *conv_spec, char *format, int i, int len);

#endif
