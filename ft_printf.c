/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 15:12:36 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/15 15:31:21 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_extract_format(const char format, va_list *args)
{
	if (format == 'c')
		return (ft_handlechar(args));
	else if (format == 's')
		return (ft_handlestr(args));
	else if (format == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (format == 'i' || format == 'd')
		return (ft_handlenbr(args));
	else if (format == 'u')
		return (ft_putusnbr(va_arg(*args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthexa(va_arg(*args, unsigned int), format));
	else
		return (ft_handleunknown(format));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_start(args, format);
	size_t	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_extract_format(format[i + 1], &args);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
#include <stdio.h>
int	main(void)
{
	ft_printf("%p\n", NULL);
	ft_printf("Value: %d end\n", 21);
	printf("%p\n", NULL);
}
