/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 23:17:34 by lmatthes          #+#    #+#             */
/*   Updated: 2026/07/26 00:47:13 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*ft_char_to_str(char c)
{
	char	*s;

	s = malloc(2);
	if (!s)
		return (0);
	s[0] = c;
	s[1] = '\0';
	return (s);
}

static char	*ft_get_num(char spec, va_list args, t_fmt *f)
{
	void	*ptr;

	f->is_num = 1;
	if (spec == 'd' || spec == 'i')
		return (ft_itoa(va_arg(args, int)));
	else if (spec == 'u')
		return (ft_utoa_base(va_arg(args, unsigned int), "0123456789"));
	else if (spec == 'x')
		return (ft_utoa_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (spec == 'X')
		return (ft_utoa_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (spec == 'p')
	{
		ptr = va_arg(args, void *);
		f->is_num = 0;
		if (!ptr)
			return (ft_strdup("(nil)"));
		return (ft_ptr_to_str((unsigned long)ptr));
	}
	f->is_num = 0;
	return (0);
}

static char	*ft_get_str(char spec, va_list args, t_fmt *f)
{
	char	*str;

	if (spec == 'c')
		return (ft_char_to_str((char)va_arg(args, int)));
	else if (spec == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		return (ft_strdup(str));
	}
	else if (spec == '%')
		return (ft_char_to_str('%'));
	return (ft_get_num(spec, args, f));
}

int	ft_dispatch(char spec, va_list args, t_fmt *f)
{
	char	*s;
	int		count;

	s = ft_get_str(spec, args, f);
	s = ft_apply_flags(s, spec, f);
	s = ft_apply_str_prec(s, f);
	s = ft_apply_prec(s, f);
	if (!s)
		return (0);
	count = ft_put_width(s, f);
	free(s);
	return (count);
}
