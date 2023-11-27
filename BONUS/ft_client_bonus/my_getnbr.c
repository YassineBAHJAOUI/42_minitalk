/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahjaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:55:20 by ybahjaou          #+#    #+#             */
/*   Updated: 2023/02/25 16:13:17 by ybahjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_getnbr(char *str)
{
	int	res;

	if (*str == '-')
		return (-ft_getnbr(str + 1));
	if (*str == '+')
		return (ft_getnbr(str + 1));
	res = 0;
	while (*str)
	{
		res *= 10;
		res += *str - '0';
		str += 1;
	}
	return (res);
}
