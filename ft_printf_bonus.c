/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 21:30:26 by lmatthes          #+#    #+#             */
/*   Updated: 2026/07/25 21:30:31 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		write(1, &format[i], 1);
		count++;
		i++;
	}
	va_end(args);
	return (count);
}
