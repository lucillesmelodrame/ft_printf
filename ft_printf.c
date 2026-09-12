/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 15:12:36 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/11 21:40:14 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_extract_format(const char format, va_list args)
{
	if (format == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (format == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (format == 'i' || format == 'd')
		ft_handle_uid(va_arg(args, int));
	else if (format == 'x' || format == 'X')
		ft_handle_hexa(va_arg(args, char *));
	else if (format == '%')
		ft_putchar_fd('%', 1);
/*	else
	{
		ft_putchar()
	} */
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_start(args, format);
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ft_extract_format(format[i + 1], &args);
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (i);
}
