/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 11:26:18 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/10 18:35:24 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONV_ID_NB 10
# define FLAGS_NB 4

typedef struct		s_conv_spec
{
	char            conv_id;
	int				*flags;
	int				*size_modif;
	int				field_width;
	int				precision;

	char*           converted;
}					t_conv_spec;

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "store/store.h"
# include "data/data.h"
# include "process/process.h"

#endif
