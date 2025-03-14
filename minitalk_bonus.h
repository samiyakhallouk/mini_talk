/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:49:11 by skhallou          #+#    #+#             */
/*   Updated: 2025/03/14 20:37:17 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
#define MINITALK_BONUS_H

                                                              
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
#include <stdio.h>
#include <string.h>

int     ft_atoi(char *s);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	send_signal(int pid, unsigned char c);
void	handler(int signal, siginfo_t *s, void *b);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);

#endif