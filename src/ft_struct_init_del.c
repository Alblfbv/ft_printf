
#include "ft_printf.h"

void	ft_struct_init(t_conv_spec *conv_spec)
{
	conv_spec->conv_id = 0;
	conv_spec->param_value_int = 0;
	conv_spec->param_value_u_int = 0;
	conv_spec->param_value_double = 0;
	conv_spec->param_value_char = NULL;
	conv_spec->param_value_void = NULL;
	conv_spec->flags = NULL;
	conv_spec->size_modif = NULL;
	conv_spec->field_width = 0;
	conv_spec->precision = 0;
}

void	ft_struct_del(t_conv_spec *conv_spec)
{
//	free(conv_spec->flags);
	free(conv_spec->size_modif);
}
