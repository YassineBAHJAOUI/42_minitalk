/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahjaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:06:24 by ybahjaou          #+#    #+#             */
/*   Updated: 2023/02/24 16:29:32 by ybahjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define TRUE 1
# define FALSE 0

void	ft_error(char *str);
int		ft_str_isnum(char *str);
int		ft_getnbr(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	sig(int nb);
void	ft_sleep(void);
void	s_sign(int pid, int nb);
void	ft_putchar(char c);

#endif
