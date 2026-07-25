/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 23:17:58 by lmatthes          #+#    #+#             */
/*   Updated: 2026/07/25 23:18:03 by lmatthes         ###   ########.fr       */
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

static int	ft_pad(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

int	ft_put_width(char *s, t_fmt *f)
{
	int	len;
	int	pad;
	int	count;

	len = ft_strlen(s);
	pad = f->width - len;
	count = len;
	if (pad < 0)
		pad = 0;
	count += pad;
	if (f->minus)
	{
		ft_putstr_len(s);
		ft_pad(pad);
	}
	else
	{
		ft_pad(pad);
		ft_putstr_len(s);
	}
	return (count);
}
