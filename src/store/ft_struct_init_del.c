/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init_del.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:08:53 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/14 18:00:12 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_struct_init(t_conv_spec *conv_spec)
{
	conv_spec->conv_id = 0;
	conv_spec->size_modif = NULL;
	conv_spec->field_width = 0;
	conv_spec->precision = -1;
	conv_spec->flags = NULL;
}

void	ft_struct_del(t_conv_spec *conv_spec)
{
	free(conv_spec->size_modif);
	free(conv_spec->flags);
}
