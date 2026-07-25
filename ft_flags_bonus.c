/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 23:37:36 by lmatthes          #+#    #+#             */
/*   Updated: 2026/07/25 23:37:42 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*ft_prepend(char *s, char *pre)
{
	char	*res;

	res = ft_strjoin(pre, s);
	free(s);
	return (res);
}

char	*ft_apply_flags(char *s, char spec, t_fmt *f)
{
	if (!s)
		return (0);
	if ((spec == 'd' || spec == 'i') && s[0] != '-')
	{
		if (f->plus)
			return (ft_prepend(s, "+"));
		if (f->space)
			return (ft_prepend(s, " "));
	}
	if ((spec == 'x' || spec == 'X') && f->hash && !(s[0] == '0' && !s[1]))
	{
		if (spec == 'x')
			return (ft_prepend(s, "0x"));
		return (ft_prepend(s, "0X"));
	}
	return (s);
}
