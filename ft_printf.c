/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 15:12:36 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/14 01:18:15 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_extract_format(const char format, va_list *args)
{
	if (format == 'c')
		ft_putchar_fd(va_arg(*args, int), 1);
	else if (format == 's')
		ft_putstr_fd(va_arg(*args, char *), 1);
	else if (format == 'p')
		ft_putptr(va_arg(*args, void *));
	else if (format == 'i' || format == 'd')
		ft_putnbr_fd(va_arg(*args, int), 1);
	else if (format == 'u')
		ft_putusnbr(va_arg(*args, unsigned int));
	else if (format == 'x' || format == 'X')
		ft_puthexa(va_arg(*args, unsigned int), format);
	else if (format == '%')
		ft_putchar_fd('%', 1);
	else
	{
		ft_putchar_fd('%', 1);
		ft_putchar_fd(format, 1);
	}
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
