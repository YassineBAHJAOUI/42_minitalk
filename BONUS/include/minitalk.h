/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybahjaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:13:46 by ybahjaou          #+#    #+#             */
/*   Updated: 2023/02/25 14:19:54 by ybahjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define TRUE 1
# define FALSE 0
# define BUFFER_SIZE 32000

char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*get_next_line(int fd);
void	ft_error(char *str);
int		my_strlen(char *s);
int		ft_str_isnum(char *str);
int		ft_getnbr(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	sig(int nb);
void	ft_sleep(void);
void	s_sign(int pid, int nb);
void	ft_putchar(char c);

#endif
