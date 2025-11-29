/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:40:37 by lmatthes          #+#    #+#             */
/*   Updated: 2025/11/29 19:41:20 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# ifdef __APPLE__
#  define FT_PRINTF_MACOS 1
# else
#  define FT_PRINTF_MACOS 0
# endif

int	ft_printf(const char *format, ...);

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putptr(unsigned long p);
int	ft_putnbr(int n);
int	ft_putuint(unsigned int n);
int	ft_puthex(unsigned int n, char format);

#endif