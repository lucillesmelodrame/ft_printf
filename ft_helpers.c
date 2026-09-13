/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 17:21:23 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/14 01:17:32 by sonfong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_putusnbr(unsigned int n)
{
	char	c;

	if (n != 0)
	{
		if (n > 9)
			ft_putusnbr(n / 10);
		n %= 10;
	}
	c = n + '0';
	write(1, &c, 1);
}

void	ft_puthexa(unsigned long n, const char format)
{
	char	c;

	if (n != 0)
	{
		if (n > 15)
			ft_puthexa(n / 16, format);
		n %= 16;
	}
	if (format == 'x')
		c = "0123456789abcdef"[n];
	else
		c = "0123456789ABCDEF"[n];
	write(1, &c, 1);
}

int	ft_putptr(void *n)
{
	unsigned long	nbr;

	nbr = (unsigned long)n;
	if (n == NULL)
		ft_putstr_fd("(nil)", 1);
	ft_putstr_fd("0x", 1);
	ft_puthexa(nbr, 'x');
}
