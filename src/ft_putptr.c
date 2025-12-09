/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:26:39 by lmatthes          #+#    #+#             */
/*   Updated: 2025/12/09 20:20:25 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_hex(unsigned long n)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
	{
		count += ft_putptr_hex(n / 16);
		count += ft_putptr_hex(n % 16);
	}
	else
		count += ft_putchar(base[n]);
	return (count);
}

int	ft_putptr(unsigned long p)
{
	if (p == 0)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	return (2 + ft_putptr_hex(p));
}
