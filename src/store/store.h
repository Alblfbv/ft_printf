#ifndef STORE_H
# define STORE_H

# include "../ft_printf.h"

char	*ft_data_conv_ids(void);
int		ft_conv_id(t_conv_spec *conv_spec, char *format, int i);
void	ft_size_modif(t_conv_spec *conv_spec, char *format, int i, int len);
void	ft_flag(t_conv_spec *conv_spec, char *format, int i, int len);
void	ft_field_width(t_conv_spec *conv_spec, char *format, int i, int len);
void	ft_precision(t_conv_spec *conv_spec, char *format, int i, int len);
void	ft_struct_init(t_conv_spec *conv_spec);
void	ft_struct_del(t_conv_spec *conv_spec);

#endif