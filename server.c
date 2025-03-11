/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhallou <skhallou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:49:48 by skhallou          #+#    #+#             */
/*   Updated: 2025/03/11 14:06:20 by skhallou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static	unsigned char	reminder;
	static	int				i;

	reminder |= (signal == SIGUSR1);
	printf("%d\n", signal);
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
	pid_t	pid;

	pid = getpid();
	ft_putstr("PID -> ");
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	while (1)
		pause();
	return 0;
}
