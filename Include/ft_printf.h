/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:21:30 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/11 14:46:51 by jfleury          ###   ########.fr       */
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
# define FLAGS_NB 4

typedef struct			s_conv_spec
{
	char				conv_id;
	int					*flags;
	int					*size_modif;
	int					field_width;
	int					precision;
	char				*converted;
}						t_conv_spec;

typedef struct		s_hexa
{
	char	*tab;
	int		value;
	int		quotien;
	int		div;
	char	*c;
	int		num_div;
	int		result;
}					t_hexa;

//typedef	char	(*t_fuck)(t_conv_spec spec, va_list *list);

typedef struct		s_fptr_id
{
	char	*conv_id_tab;
//	t_fuck	tab[CONV_ID_NB];
	char	*(*fptr)[CONV_ID_NB](t_conv_spec conv_spec, va_list *list);
}					t_fptr_id;

typedef struct		s_fptr_flag
{
	int				*flags;
	char			*(*fptr[4])(t_conv_spec conv_spec, char *str);
}					t_fptr_flag;

char	*ft_data_conv_ids(void);
int		ft_conv_id(t_conv_spec *conv_spec, char *format, int i);
void	ft_size_modif(t_conv_spec *conv_spec, char *format, int i, int len);
void	ft_flag(t_conv_spec *conv_spec, char *format, int i, int len);
void	ft_field_width(t_conv_spec *conv_spec, char *format, int i, int len);
void	ft_precision(t_conv_spec *conv_spec, char *format, int i, int len);
void	ft_struct_init(t_conv_spec *conv_spec);
void	ft_struct_del(t_conv_spec *conv_spec);

char	*ft_data_conv_ids(void);

char	*ft_process_c(t_conv_spec conv_spec, va_list *ap);
char	*ft_process_s(t_conv_spec conv_spec, va_list *ap);
char	*ft_process_p(t_conv_spec conv_spec, va_list *ap);
char	*ft_process_di(t_conv_spec conv_spec, va_list *ap);
char	*ft_process_table(t_conv_spec conv_spec, va_list *ap);
char	*ft_process_flags(t_conv_spec, char *str);
char	*ft_process_hash(t_conv_spec, char *str);


#endif
