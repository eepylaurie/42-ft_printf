/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 21:32:46 by lmatthes          #+#    #+#             */
/*   Updated: 2026/07/25 23:28:37 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_init_fmt(t_fmt *f)
{
	f->minus = 0;
	f->zero = 0;
	f->hash = 0;
	f->plus = 0;
	f->space = 0;
	f->width = 0;
	f->prec = -1;
	f->is_num = 0;
}

static int	ft_parse_flags(const char *fmt, int i, t_fmt *f)
{
	while (fmt[i] == '-' || fmt[i] == '0' || fmt[i] == '#'
		|| fmt[i] == '+' || fmt[i] == ' ')
	{
		if (fmt[i] == '-')
			f->minus = 1;
		else if (fmt[i] == '0')
			f->zero = 1;
		else if (fmt[i] == '#')
			f->hash = 1;
		else if (fmt[i] == '+')
			f->plus = 1;
		else if (fmt[i] == ' ')
			f->space = 1;
		i++;
	}
	return (i);
}

static int	ft_parse_width(const char *fmt, int i, t_fmt *f)
{
	while (fmt[i] >= '0' && fmt[i] <= '9')
	{
		f->width = f->width * 10 + (fmt[i] - '0');
		i++;
	}
	return (i);
}

static int	ft_parse_prec(const char *fmt, int i, t_fmt *f)
{
	if (fmt[i] == '.')
	{
		f->prec = 0;
		i++;
		while (fmt[i] >= '0' && fmt[i] <= '9')
		{
			f->prec = f->prec * 10 + (fmt[i] - '0');
			i++;
		}
	}
	return (i);
}

int	ft_parse_fmt(const char *fmt, int i, t_fmt *f)
{
	ft_init_fmt(f);
	i = ft_parse_flags(fmt, i, f);
	i = ft_parse_width(fmt, i, f);
	i = ft_parse_prec(fmt, i, f);
	return (i);
}
