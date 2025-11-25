/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:07:59 by lmatthes          #+#    #+#             */
/*   Updated: 2025/11/25 21:14:01 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuint(unsigned int n)
{
	if (n >= 10)
		return (ft_putuint(n / 10) + ft_putuint(n % 10));
	return (ft_putchar(n + '0'));
}
