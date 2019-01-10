#include "process.h"

char	*ft_process_di(t_conv_spec conv_spec, va_list *ap)
{
	char	*str;

	str = ft_itoa(va_arg(*ap, int));
	return (str);
}
