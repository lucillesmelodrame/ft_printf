/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 15:13:46 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/13 23:38:05 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *, ...);
void	ft_putusnbr(unsigned int n);
void	ft_putptr(void *n);
void	ft_puthexa(unsigned long n, const char format);
void	ft_extract_format(const char format, va_list *args);

#endif
