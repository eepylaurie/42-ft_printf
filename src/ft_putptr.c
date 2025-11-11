/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:42:20 by lmatthes          #+#    #+#             */
/*   Updated: 2025/11/11 16:15:38 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *p)
{
	unsigned long	address;
	int				count;

	address = (unsigned long)p;
	count = 0;
	if (address == 0)
		return (count += write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += ft_puthex(address, 'p');
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	void	*ptr;
// 	int		num;

// 	num = 42;
// 	ptr = &num;
// 	int	ret1 = printf("%p", ptr);
// 	printf("\n");
// 	int	ret2 = ft_printf("%p", ptr);
// 	printf("\n");
// 	printf("ret1: %d | ret2: %d", ret1, ret2);
// }
