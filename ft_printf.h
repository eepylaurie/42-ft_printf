/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 20:02:59 by lmatthes          #+#    #+#             */
/*   Updated: 2026/07/25 20:44:13 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_format(char specifier, va_list args);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_puthex(unsigned int n, char *base);
int	ft_puthex_long(unsigned long n);
int	ft_putptr(void *ptr);

#endif