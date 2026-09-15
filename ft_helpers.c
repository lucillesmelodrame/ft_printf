/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 17:21:23 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/14 02:14:31 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_putusnbr(unsigned int n)
{
	char	c;
	int	count;

	count = 0;
	if (n != 0)
	{
		if (n > 9)
			ft_putusnbr(n / 10);
		n %= 10;
	}
	c = n + '0';
	count += write(1, &c, 1);
	return (count);
}

int	ft_puthexa(unsigned long n, const char format)
{
	char	c;
	int	count;

	count = 0;
	if (n != 0)
	{
		if (n > 15)
			count += ft_puthexa(n / 16, format);
		n %= 16;
	}
	if (format == 'x')
		c = "0123456789abcdef"[n];
	else
		c = "0123456789ABCDEF"[n];
	count += write(1, &c, 1);
	return (count);
}

int	ft_putptr(void *n)
{
	unsigned long	nbr;
	int	count;

	nbr = (unsigned long)n;
	count = 0;
	if (n == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (0);
	}
	ft_putstr_fd("0x", 1);
	count += 2;
	count += ft_puthexa(nbr, 'x');
	return (count);
}
