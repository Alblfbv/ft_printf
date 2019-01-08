/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 11:26:18 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/07 18:47:40 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

# define CONV_ID_NB 10

typedef struct		s_conv_spec
{
	char            conv_id;
	int				*flags;
	int				*size_modif;
	int				field_width;
	int				precision;

	char*           converted;
}					t_conv_spec;

char	*ft_data_conv_ids(void);
int		ft_conv_id(t_conv_spec *conv_spec, char *format, int i);
void	ft_size_modif(t_conv_spec *conv_spec, char *format, int i, int len);
void	ft_flag(t_conv_spec *conv_spec, char *format, int i, int len);
void	ft_field_width(t_conv_spec *conv_spec, char *format, int i, int len);
void	ft_precision(t_conv_spec *conv_spec, char *format, int i, int len);
void	ft_struct_init(t_conv_spec *conv_spec);
void	ft_struct_del(t_conv_spec *conv_spec);

#endif
