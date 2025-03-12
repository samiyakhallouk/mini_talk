/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:49:59 by skhallou          #+#    #+#             */
/*   Updated: 2025/03/12 17:02:44 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

                                                              
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int     ft_atoi(char *s);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	send_signal(int pid, unsigned char c);
void	handler(int signal, siginfo_t *s, void *b);

#endif