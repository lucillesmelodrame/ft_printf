/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/11 10:13:00 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/11 21:58:34 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "ft_printf.h"
/*
void	ft_handle_hexa(int decimal)
{
//	int	decimal;
	int	i;
	int	temp;
	char	hexa[32];

//	decimal = va_arg(args, int);
	i = 1;
	while (decimal != 0)
	{
		temp = decimal % 16;
		if (temp < 10)
			temp += 48;
		else
			temp += 55;
		hexa[i] = temp;
		decimal /= 16;
		i++;
	}
} */
#include <stdio.h>
int	main(void)
{
	printf("%x, %X", 45, 45);
	return (0);
}
