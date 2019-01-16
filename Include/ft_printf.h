/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:21:30 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/16 13:46:00 by allefebv         ###   ########.fr       */
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
# define FLAGS_NB 5
# define PRECI_GROUPS 2

typedef struct	s_conv_spec
{
	char		conv_id;
	int			*flags;
	int			*modifier;
	int			field_width;
	int			precision;
	char		*converted;
}				t_conv_spec;

typedef struct	s_hexa
{
	char		*tab;
	int			value;
	int			quotien;
	int			div;
	char		*c;
	int			num_div;
	int			result;
}				t_hexa;

typedef struct	s_fptr_id
{
	char		*conv_id_tab;
	char		*(*fptr[CONV_ID_NB])(t_conv_spec c_s, va_list *list);
}				t_fptr_id;

typedef struct	s_fptr_flag
{
	int			*flags;
	char		*(*fptr[FLAGS_NB])(t_conv_spec c_s, char *str);
}				t_fptr_flag;

typedef struct	s_fptr_preci
{
	char		**preci_group;
	char		*(*fptr[PRECI_GROUPS])(t_conv_spec c_s, char *str);
}				t_fptr_preci;

char			*ft_data_conv_ids(void);
int				ft_conv_id(t_conv_spec *c_s, char *format, int i);
void			ft_modifier(t_conv_spec *c_s, char *format, int i, int len);
void			ft_flag(t_conv_spec *c_s, char *format, int i, int len);
void			ft_field_width(t_conv_spec *c_s, char *format, int i, int len);
void			ft_precision(t_conv_spec *c_s, char *format, int i, int len);
void			ft_struct_init(t_conv_spec *c_s);
void			ft_struct_del(t_conv_spec *c_s);

char			*ft_data_conv_ids(void);

char			*ft_process_c(t_conv_spec c_s, va_list *ap);
char			*ft_process_s(t_conv_spec c_s, va_list *ap);
char			*ft_process_p(t_conv_spec c_s, va_list *ap);
char			*ft_process_di(t_conv_spec c_s, va_list *ap);
char			*ft_process_o(t_conv_spec c_s, va_list *ap);
char			*ft_process_u(t_conv_spec c_s, va_list *ap);
char			*ft_process_x(t_conv_spec c_s, va_list *ap);
char			*ft_process_xx(t_conv_spec c_s, va_list *ap);
char			*ft_process_f(t_conv_spec c_s, va_list *ap);
char			*ft_process_id(t_conv_spec c_s, va_list *ap);
char			*ft_process_flags(t_conv_spec c_s, char *str);
char			*ft_process_hash(t_conv_spec c_s, char *str);
char			*ft_process_plus(t_conv_spec c_s, char *str);
char			*ft_process_zero(t_conv_spec c_s, char *str);
char			*ft_process_minus(t_conv_spec c_s, char *str);
char			*ft_process_space(t_conv_spec c_s, char *str);

char			*ft_process_min_width(t_conv_spec c_s, char *str);

char			*ft_precision_diouxx(t_conv_spec c_s, char *str);
char			*ft_precision_s(t_conv_spec c_s, char *str);
char			*ft_process_preci(t_conv_spec c_s, char *str);

#endif
