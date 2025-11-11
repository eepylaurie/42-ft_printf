/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:19:59 by lmatthes          #+#    #+#             */
/*   Updated: 2025/11/11 16:38:15 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		ret1;
	int		ret2;
	void	*ptr;
	int		num;

	ret1 = printf("%c %c %c", 'A', 0, 'Z');
	printf("\n");
	ret2 = ft_printf("%c %c %c", 'A', 0, 'Z');
	printf("\nprintf returns: %d\n", ret1);
	printf("ft_printf returns: %d\n\n", ret2);

	ret1 = printf("%s", "Hello World");
	printf("\n");
	ret2 = ft_printf("%s", "Hello World");
	printf("\nprintf returns: %d\n", ret1);
	printf("ft_printf returns: %d\n\n", ret2);
	ret1 = printf("%s", (char *) NULL);
	printf("\n");
	ret2 = ft_printf("%s", (char *) NULL);
	printf("\nprintf returns: %d\n", ret1);
	printf("ft_printf returns: %d\n\n", ret2);

	num = 42;
	ptr = &num;
	ret1 = printf("%p", ptr);
	printf("\n");
	ret2 = ft_printf("%p", ptr);
	printf("\nprintf returns: %d\n", ret1);
	printf("ft_printf returns: %d\n\n", ret2);

	ptr = NULL;
	ret1 = printf("%p", ptr);
	printf("\n");
	ret2 = ft_printf("%p", ptr);
	printf("\nprintf returns: %d\n", ret1);
	printf("ft_printf returns: %d\n\n", ret2);

	ret1 = printf("%d %d %d | %i %i %i", INT_MAX, 0, INT_MIN, INT_MAX, 0, INT_MIN);
	printf("\n");
	ret2 = ft_printf("%d %d %d | %i %i %i", INT_MAX, 0, INT_MIN, INT_MAX, 0, INT_MIN);
	printf("\nprintf returns: %d\n", ret1);
	printf("ft_printf returns: %d\n\n", ret2);

	ret1 = printf("%u %u", 0, UINT_MAX);
	printf("\n");
	ret2 = ft_printf("%u %u", 0, UINT_MAX);
	printf("\nprintf returns: %d\n", ret1);
	printf("ft_printf returns: %d\n\n", ret2);

	ret1 = printf("%x %X %x", num, num, UINT_MAX);
	printf("\n");
	ret2 = ft_printf("%x %X %x", num, num, UINT_MAX);
	printf("\nprintf returns: %d\n", ret1);
	printf("ft_printf returns: %d\n\n", ret2);

	ret1 = printf("%%");
	printf("\n");
	ret2 = ft_printf("%%");
	printf("\nprintf returns: %d\n", ret1);
	printf("ft_printf returns: %d\n\n", ret2);
}
