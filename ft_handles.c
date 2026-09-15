/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 10:13:05 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/15 15:31:05 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handlechar(va_list *args)
{
	int	count;

	count = 0;
	ft_putchar_fd(va_arg(*args, int), 1);
	count++;
	return (count);
}

int	ft_handlestr(va_list *args)
{
	int	count;
	char	*str;

	count = 0;
	str = va_arg(*args, char *);
	ft_putstr_fd(str, 1);
	count = ft_strlen(str);
	return (count);
}

int	ft_handlenbr(va_list *args)
{
	int	count;
	char	*str;

	str = ft_itoa(va_arg(*args, int));
	count = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (count);
}

int	ft_handleunknown(const char format)
{
	int	count;
	
	count = 0;
	ft_putchar_fd('%', 1);
	count++;
	if (format != '%')
	{
		ft_putchar_fd('%', 1);
		ft_putchar_fd(format, 1);
		count += 2;
	}
	return (count);
}
