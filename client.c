/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:49:36 by skhallou          #+#    #+#             */
/*   Updated: 2025/03/14 14:57:45 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	protection(int r)
{
	if (r == -1)
		exit(1);
		
}
void	check_sig(int sig)
{
	if (sig == SIGUSR1)
		return ;
}

void	send_signal(int pid, unsigned char c)
{
	int				i;
	unsigned char	tmp;

	tmp = c;
	i = 8;
	signal(SIGUSR1, check_sig);
	while (i)
	{
		i--;
		tmp = c >> i;
		if (tmp % 2 == 0)
			protection(kill(pid, SIGUSR2));
		else
			protection(kill(pid, SIGUSR1));
		pause();
	}
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;

	if (ac != 3)
	{
		ft_putstr("Invalid number of arguments\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (1);
	i = 0;
	while (av[2][i])
		send_signal(pid, av[2][i++]);
	send_signal(pid, '\0');
	return (0);
}
