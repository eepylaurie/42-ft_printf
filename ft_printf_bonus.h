/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 21:30:06 by lmatthes          #+#    #+#             */
/*   Updated: 2026/07/25 21:30:11 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_fmt
{
	int	minus;
	int	zero;
	int	hash;
	int	plus;
	int	space;
	int	width;
	int	prec;
}	t_fmt;

int	ft_printf(const char *format, ...);

#endif