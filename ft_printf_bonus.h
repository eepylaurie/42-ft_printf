/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatthes <lmatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 21:30:06 by lmatthes          #+#    #+#             */
/*   Updated: 2026/07/25 23:22:50 by lmatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

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

int		ft_printf(const char *format, ...);
void	ft_init_fmt(t_fmt *f);
int		ft_parse_fmt(const char *format, int i, t_fmt *f);
int		ft_dispatch(char spec, va_list args, t_fmt *f);
int		ft_put_width(char *s, t_fmt *f);
char	*ft_utoa_base(unsigned long n, char *base);
char	*ft_ptr_to_str(unsigned long n);

#endif