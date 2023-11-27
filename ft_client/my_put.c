/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahjaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:40:08 by ybahjaou          #+#    #+#             */
/*   Updated: 2023/02/24 16:44:16 by ybahjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr(int nb)
{
	int	neg;

	neg = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			neg = 1;
			nb++;
		}
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	if (neg == 1)
	{
		neg = 0;
		ft_putchar(nb % 10 + '1');
	}
	else
		ft_putchar(nb % 10 + '0');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}
