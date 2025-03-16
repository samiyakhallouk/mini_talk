/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:49:48 by skhallou          #+#    #+#             */
/*   Updated: 2025/03/14 21:23:48 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	protection(int r)
{
	if (r == -1)
		exit(1);
		
}

void	handler(int signal, siginfo_t *s, void *b)
{
	static unsigned char	reminder;
	static int				i;
	static int				cpid;

	(void)b;
	if (s->si_pid != cpid)
	{
		cpid = s->si_pid;
		i = 0;
		reminder = 0;
	}
	reminder = (reminder << 1) | (signal == SIGUSR1);
	i++;
	if (i == 8)
	{
		write(1, &reminder, 1);
		reminder = 0;
		i = 0;
	}
	usleep(500);
	kill(s->si_pid, SIGUSR1);
}

int	main(void)
{
	int	pid;
	struct sigaction	s;

	pid = getpid();
	ft_putstr("PID -> ");
	ft_putnbr(pid);
	ft_putchar('\n');
	s.sa_sigaction = handler;
	s.sa_flags = SA_SIGINFO;
	protection(sigaction(SIGUSR2, &s, NULL));
	protection(sigaction(SIGUSR1, &s, NULL));
	while (1)
		pause();
	return 0;
}
