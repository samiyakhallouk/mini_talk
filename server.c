/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:49:48 by skhallou          #+#    #+#             */
/*   Updated: 2025/03/11 17:48:21 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	protection(int r)
{
	if (r == -1)
		exit(1);
		
}

void	handler(int signal)
{
	static	unsigned char	reminder;
	static	int				i;

	reminder |= (signal == SIGUSR1);
	i++;
	if (i == 8)
	{
		ft_putchar(reminder);
		reminder = 0;
		i = 0;
	}
	else
		reminder <<= 1;

}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr("PID -> ");
	ft_putnbr(pid);
	ft_putchar('\n');
	protection(signal(SIGUSR2, handler));
	protection(signal(SIGUSR1, handler));
	while (1)
		pause();
	return 0;
}
