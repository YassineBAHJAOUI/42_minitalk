/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahjaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:22:36 by ybahjaou          #+#    #+#             */
/*   Updated: 2023/02/26 14:08:41 by ybahjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "minitalk.h"

void	s_sign(int pid, int nb)
{
	if (nb == 0)
		if (kill(pid, SIGUSR1) == -1)
			ft_error("\033[91mERROR : cannot send SIGUSR1\033[0m\n");
	if (nb == 1)
		if (kill(pid, SIGUSR2) == -1)
			ft_error("\033[91mERROR : cannot send SIGUSR2\033[0m\n");
}

void	tr_sign(int pid, char to_send)
{
	char	c;
	int		nb;

	c = 0;
	while (c < 8)
	{
		nb = (to_send >> c++) & 1;
		usleep(800);
		s_sign(pid, nb);
	}
}

void	tr_char(int pid, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		tr_sign(pid, str[i]);
	tr_sign(pid, 0);
}

void	put_beg(int pid_serv)
{
	ft_putstr("\033[0;37mConnection with the server at the PID \033[0m#");
	ft_putnbr(pid_serv);
	ft_putstr(" ...\n");
	sleep(1);
	ft_putstr("\033[1;32mDone.\033[0m\n");
}

int	main(int ac, char **av)
{
	pid_t	pid_serv;
	char	*mess;

	if (ac != 2)
		ft_error("\033[0;31mError Try : ./client PID_serv\033[0m\n");
	if (ft_str_isnum(av[1]) == 0)
		pid_serv = ft_getnbr(av[1]);
	else
		ft_error("\033[91mERROR : First arg must be a number\033[0m\n");
	if (pid_serv <= 1)
		ft_error("\033[[91mBad PID\033[0m\n");
	put_beg(pid_serv);
	ft_putstr("\033[0;34mWelcome,press CTRL + D to quit client\033[0m\n");
	ft_putstr("\033[90mEnter message here :\033[0m\n");
	mess = get_next_line(0);
	while (mess != NULL)
	{
		ft_putstr("\033[90mEnter message here :\033[0m\n");
		tr_char(pid_serv, mess);
		free(mess);
		mess = get_next_line(0);
	}
	if (mess == NULL)
		ft_putstr("\033[0;32m--------END OF TRANSMISSION--------\033[0m\n");
	return (0);
}
