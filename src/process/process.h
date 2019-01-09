#ifndef PROCESS_H
# define PROCESS_H

# include "../ft_printf.h"

typedef struct		s_fptr
{
	char	conv_id;
	char	*(*fptr)(t_conv_spec, va_list*);
}					t_fptr;

char	*ft_process_c(t_conv_spec conv_spec, va_list *ap);
char	*ft_process_table(t_conv_spec conv_spec, va_list *ap);

#endif

