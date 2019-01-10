/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:21:38 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/10 14:29:02 by allefebv         ###   ########.fr       */
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

typedef struct		s_fptr
{
	char	conv_id;
	char	*(*fptr)(t_conv_spec, va_list*);
}					t_fptr;

char	*ft_process_c(t_conv_spec conv_spec, va_list *ap);
char	*ft_process_s(t_conv_spec conv_spec, va_list *ap);
char	*ft_process_p(t_conv_spec conv_spec, va_list *ap);
char	*ft_process_table(t_conv_spec conv_spec, va_list *ap);

#endif
