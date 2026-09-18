/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 15:13:46 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/15 15:48:31 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_putusnbr(unsigned int n);
int	ft_putptr(void *n);
int	ft_puthexa(unsigned long n, const char format);
int	ft_extract_format(const char format, va_list *args);
int	ft_handlechar(va_list *args);
int	ft_handlenbr(va_list *args);
int	ft_handlestr(va_list *args);
int	ft_handleunknown(const char format);

#endif
