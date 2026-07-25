/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 23:29:00 by lmatthes          #+#    #+#             */
/*   Updated: 2026/07/25 23:43:18 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*ft_build_prec(char *s, int neg, int zeros)
{
	char	*res;
	int		i;
	int		len;

	len = ft_strlen(s);
	res = malloc(len + zeros + 1);
	if (!res)
		return (0);
	i = 0;
	if (neg)
		res[i++] = s[0];
	while (zeros-- > 0)
		res[i++] = '0';
	ft_strlcpy(res + i, s + neg, len - neg + 1);
	return (res);
}

char	*ft_apply_prec(char *s, t_fmt *f)
{
	char	*res;
	int		neg;
	int		len;

	if (!s || !f->is_num || f->prec < 0)
		return (s);
	neg = (s[0] == '-' || s[0] == '+' || s[0] == ' ');
	len = ft_strlen(s) - neg;
	if (f->prec == 0 && len == 1 && s[neg] == '0')
	{
		free(s);
		return (ft_strdup(""));
	}
	if (f->prec <= len)
		return (s);
	res = ft_build_prec(s, neg, f->prec - len);
	free(s);
	return (res);
}
