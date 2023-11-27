/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahjaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:30:56 by ybahjaou          #+#    #+#             */
/*   Updated: 2023/02/24 18:15:32 by ybahjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/* La boucle while parcourt chaque bit de to_send en déplaçant
la valeur binaire de to_send d'un bit vers la droite à chaque 
itération, puis en masquant le résultat avec l'opérateur & 
pour récupérer le bit de poids faible. Le résultat est stocké dans nb.
*L'opérateur de décalage binaire à droite >> est utilisé pour 
déplacer la valeur binaire de to_send d'un nombre de bits égal 
à la valeur actuelle de c. Le résultat est stocké dans to_send >> c.
*L'opérateur & est utilisé pour masquer le résultat avec la valeur 
binaire 1. Cela a pour effet de récupérer le bit de poids faible de to_send >> c.
*Enfin, l'opérateur d'incrémentation ++ est utilisé pour augmenter 
la valeur de c de 1, de sorte que la prochaine itération de la 
boucle extraira le bit suivant de to_send.
*La fonction usleep est appelée pour ralentir l'envoi de 
chaque bit, de sorte que le serveur dispose du temps nécessaire
pour recevoir chaque bit. Ici, un délai de 800 microsecondes 
(soit 0,8 milliseconde) est utilisé. 
*/

void	sign(int pid, char to_send)
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

void	tre_char(int pid, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		sign(pid, str[i]);
	sign(pid, 0);
}
/* main est la fonction principale
*prend en argument le nombre d'arguments (ac) 
et un tableau de chaînes de caractères (av).
*vérifie si le nombre d'arguments est 
différent de 3 Si c'est le cas,  affiche 
un message d'erreur en rouge et termine le programme.
*Si le nombre d'arguments est correct, vérifie que 
le premier argument (av[1]) est un nombre valide 
en appelant la fonction ft_str_isnum. Si c'est le cas, 
elle convertit le premier argument en entier avec la fonction 
ft_getnbr et le stocke dans la variable pid_serv. 
Sinon, elle affiche un message d'erreur en rouge et termine le programme.
*vérifie que le PID est supérieur à 1. Si ce n'est pas
le cas, cela signifie que le PID est invalide, et
elle affiche un message d'erreur en rouge 
et termine le programme.
*Enfin, elle appelle la fonction tre_char avec 
le PID et le message à envoyer (av[2]).
*/

int	main(int ac, char **av)
{
	pid_t	pid_serv;

	if (ac != 3)
	{
		ft_putstr("\033[91mError: Wrong format.\033[0m\n");
		ft_error("\033[33mTry : ./client <Pid> <message>\033[0m\n");
	}
	if (ft_str_isnum(av[1]) == 0)
		pid_serv = ft_getnbr(av[1]);
	else
		ft_error("\033[91mERROR : First arg must be a number\033[0m\n");
	if (pid_serv <= 1)
		ft_error("\033[91mBad PID\033[0m\n");
	tre_char(pid_serv, av[2]);
	return (0);
}
