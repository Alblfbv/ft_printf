/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:21:38 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/10 18:51:01 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "../ft_printf.h"

typedef struct		h_hexa
{
	char	*tab;
	int		value;
	int		quotien;
	int		div;
	char	*c;
	int		num_div;
	int		result;

}					t_hexa;

typedef struct		s_fptr_id
{
	char*	conv_id_tab;
	char	*(*fptr[CONV_ID_NB])(t_conv_spec, va_list*);
}					t_fptr_id;

typedef struct		s_fptr_flag
{
	int*	flags;
	char	*(*fptr[4])(t_conv_spec, char*);
}					t_fptr_flag;

char	*ft_process_c(t_conv_spec conv_spec, va_list *ap);
char	*ft_process_s(t_conv_spec conv_spec, va_list *ap);
char	*ft_process_p(t_conv_spec conv_spec, va_list *ap);
char	*ft_process_di(t_conv_spec conv_spec, va_list *ap);
char	*ft_process_table(t_conv_spec conv_spec, va_list *ap);
char	*ft_process_flags(t_conv_spec, char *str);
char	*ft_process_hash(t_conv_spec, char *str);

#endif
