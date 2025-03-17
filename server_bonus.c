/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:45:22 by skhallou          #+#    #+#             */
/*   Updated: 2025/03/14 21:41:20 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	protection(int r)
{
	if (r == -1)
		exit(1);
}

void	free_tab(char **tab)
{
	free(*tab);
	*tab = NULL;
}

void	write_tab(char **tab, int *pid)
{
	ft_putstr(*tab);
	free_tab(tab);
	kill(*pid, SIGUSR2);
}

void	handler(int signal, siginfo_t *s, void *b)
{
	static char	reminder;
	static int	i;
	static int	cpid;
	static char	*tab;

	(void)b;
	if (s->si_pid != cpid)
	{
		cpid = s->si_pid;
		i = 0;
		reminder = 0;
		free_tab(&tab);
	}
	reminder = (reminder << 1) | (signal == SIGUSR1);
	i++;
	if (i == 8)
	{
		tab = ft_strjoin(tab, &reminder);
		if (reminder == '\0')
			write_tab(&tab, &cpid);
		i = 0;
		reminder = 0;
	}
	usleep(500);
	kill(s->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
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
	return (0);
}
