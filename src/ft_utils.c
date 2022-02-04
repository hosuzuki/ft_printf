#include "ft_printf.h"
#include "../libft/libft.h"

void	ft_write(t_stock *lst, char	*content, int len)
{
	lst->total_len += write(1, &content, len);
	lst->width--;
}
