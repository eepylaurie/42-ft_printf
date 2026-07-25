/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 23:21:41 by lmatthes          #+#    #+#             */
/*   Updated: 2026/07/25 23:22:30 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_baselen(unsigned long n, int base)
{
	int	len;

	len = 1;
	while (n >= (unsigned long)base)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_utoa_base(unsigned long n, char *base)
{
	int		len;
	int		blen;
	char	*s;

	blen = ft_strlen(base);
	len = ft_baselen(n, blen);
	s = malloc(len + 1);
	if (!s)
		return (0);
	s[len] = '\0';
	while (len > 0)
	{
		s[--len] = base[n % blen];
		n /= blen;
	}
	return (s);
}

char	*ft_ptr_to_str(unsigned long n)
{
	char	*hex;
	char	*s;

	hex = ft_utoa_base(n, "0123456789abcdef");
	if (!hex)
		return (0);
	s = ft_strjoin("0x", hex);
	free(hex);
	return (s);
}
