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
void	send_signal(pid_t pid, unsigned char c);

#endif