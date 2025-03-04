#ifndef MINITALK_H
#define MINITALK_H

                                                              
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int     ft_atoi(char *s);
void	*ft_putstr(char *s);
void	send_signal(int pid, unsigned char c);

#endif