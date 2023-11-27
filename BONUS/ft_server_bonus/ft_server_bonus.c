/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahjaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:45:42 by ybahjaou          #+#    #+#             */
/*   Updated: 2023/02/26 14:24:38 by ybahjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include "minitalk.h"

void	put_serv(void)
{
	ft_putstr("\033[94mPID\033[0m \033[96m->\033[0m ");
	ft_putnbr(getpid());
	ft_putstr("\n\033[90mWaiting for message ...\033[0m\n");
}

void	ft_write(int to_put)
{
	static unsigned char	c = 0;
	static int				i = 0;

	c |= (to_put << i++);
	if (i > 7)
	{
		if (c == '\0')
		{
			ft_putchar('\n');
			ft_putchar(c);
			ft_putstr("\033[96m---------------------------\033[0m\n");
		}
		else
			ft_putchar(c);
		i = 0;
		c = 0;
	}
}

void	sig(int sign)
{
	if (sign == SIGUSR1)
		ft_write(0);
	else if (sign == SIGUSR2)
		ft_write(1);
}

void	get_sig(void)
{
	if (signal(SIGUSR1, sig) == SIG_ERR)
		ft_error("\033[91mSIGUSR1 ERROR\033[0m\n");
	if (signal(SIGUSR2, sig) == SIG_ERR)
		ft_error("\033[91mSIGUSR2 ERROR\033[0m\n");
}

int	main(int ac, char **av)
{
	if (ac != 1)
	{
		ft_putstr("\033[91mNo parameters needed\033[0m\n");
		ft_error("\033[33mTry : ./server_bonus\033[0m\n");
	}
	put_serv();
	get_sig();
	signal(SIGWINCH, SIG_IGN);
	while (42)
		pause();
	(void)av;
	return (0);
}
