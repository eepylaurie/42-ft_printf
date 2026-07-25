/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 23:17:58 by lmatthes          #+#    #+#             */
/*   Updated: 2026/07/25 23:34:06 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_putstr_len(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

static int	ft_pad(int n, char c)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

static int	ft_use_zero(t_fmt *f)
{
	if (f->minus)
		return (0);
	if (f->is_num && f->prec >= 0)
		return (0);
	return (f->zero);
}

static int	ft_put_zero(char *s, int pad)
{
	int	count;
	int	neg;

	neg = (s[0] == '-' || s[0] == '+' || s[0] == ' ');
	count = 0;
	if (neg)
		count += write(1, &s[0], 1);
	count += ft_pad(pad, '0');
	count += ft_putstr_len(s + neg);
	return (count);
}

int	ft_put_width(char *s, t_fmt *f)
{
	int	len;
	int	pad;

	len = ft_strlen(s);
	pad = f->width - len;
	if (pad < 0)
		pad = 0;
	if (f->minus)
		return (ft_putstr_len(s) + ft_pad(pad, ' '));
	if (ft_use_zero(f))
		return (ft_put_zero(s, pad));
	return (ft_pad(pad, ' ') + ft_putstr_len(s));
}
