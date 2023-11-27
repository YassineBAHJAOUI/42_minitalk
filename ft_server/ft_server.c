/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahjaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:52:24 by ybahjaou          #+#    #+#             */
/*   Updated: 2023/02/26 14:18:56 by ybahjaou         ###   ########.fr       */
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
	ft_putstr("\n\033[90mWaiting for a message...\033[0m\n");
}
/*La fonction prend en entrée un entier to_put
qui peut avoir une valeur de 0 ou 1,
correspondant à un bit du message binaire à reconstruire. 

*À chaque appel de la fonction, to_put est ajouté à c
en utilisant un décalage binaire (to_put << i++).
L'opérateur |= est utilisé pour combiner to_put avec
les bits précédemment stockés dans c. L'opérateur de
décalage binaire << est utilisé pour décaler to_put à gauche de i bits.

*La fonction vérifie ensuite si le caractère binaire
est complet (8 bits). Si oui, elle affiche le caractère
ASCII correspondant à l'aide de ft_putchar(). Si le caractère
binaire complet est le caractère nul (\0), la fonction affiche
un saut de ligne (\n) avant d'afficher le caractère nul. Enfin,
i et c sont réinitialisés à 0 pour préparer la reconstruction
du prochain caractère binaire. 
*/

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
/*
la fonction signal() prend deux arguments,
Le pointeur de fonction doit correspondre à 
un gestionnaire de signal valide, qui sera exécuté
en mode asynchrone, c'est-à-dire qu'il sera exécuté
en arrière-plan pendant que le processus principal
continue son exécution.*/

void	get_sig(void)
{
	if (signal(SIGUSR1, sig) == SIG_ERR)
		ft_error("SIGUSR1 ERROR\n");
	if (signal(SIGUSR2, sig) == SIG_ERR)
		ft_error("SIGUSR2 ERROR\n");
}
/* la fonction put_serv() est appelée pour afficher des 
informations sur le processus en cours, suivie de get_sig()
qui initialise les gestionnaires de signal pour SIGUSR1 et SIGUSR2.
La ligne signal(SIGWINCH, SIG_IGN); ignore le signal 
SIGWINCH, qui est envoyé lorsqu'une fenêtre est redimensionnée.

*Enfin, la boucle while (42) utilise la fonction 
système pause() pour suspendre le processus jusqu'à ce qu'un signal soit reçu 
*/

int	main(int ac, char **av)
{
	if (ac != 1)
	{
		ft_putstr("\033[91mNo parameters needed\033[0m\n");
		ft_error("\033[33mTry : ./server\033[0m\n");
	}
	put_serv();
	get_sig();
	signal(SIGWINCH, SIG_IGN);
	while (42)
		pause();
	(void)av;
	return (0);
}
