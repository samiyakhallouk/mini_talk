/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:49:36 by skhallou          #+#    #+#             */
/*   Updated: 2025/03/16 15:43:34 by skhallou         ###   ########.fr       */
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

void	send_signal(pid_t pid, unsigned char c)
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

int	is_valid(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
		{
			ft_putstr("Invalid PID\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	if (ac != 3)
	{
		ft_putstr("Invalid number of arguments\n");
		return (1);
	}
	if (is_valid(av[1]) == 0)
		return (1);
	pid = ft_atoi(av[1]);
	if (pid <= 0 || pid > 4194304)
	{
		ft_putstr("Invalid PID\n");
		return (1);
	}
	i = 0;
	while (av[2][i])
		send_signal(pid, av[2][i++]);
	send_signal(pid, '\0');
	return (0);
}
