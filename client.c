/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:49:36 by skhallou          #+#    #+#             */
/*   Updated: 2025/03/11 13:44:18 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(pid_t pid, unsigned char c)
{
	int				i;
	unsigned char	tmp;

	tmp = c;
	i = 8;
	while (i > 0)
	{
		i--;
		tmp = c >> i;
		if (tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
	}
	
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	if (ac != 3)
	{
		ft_putstr("Invalid number of arguments");
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