/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 23:17:34 by lmatthes          #+#    #+#             */
/*   Updated: 2026/07/25 23:17:41 by lmatthes         ###   ########.fr       */
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

int	ft_dispatch(char spec, va_list args, t_fmt *f)
{
	char	*s;
	int		count;

	if (spec == 'c')
		s = ft_char_to_str((char)va_arg(args, int));
	else if (spec == 's')
		s = ft_strdup(va_arg(args, char *));
	else if (spec == '%')
		s = ft_char_to_str('%');
	else
		return (0);
	if (!s)
		return (0);
	count = ft_put_width(s, f);
	free(s);
	return (count);
}
