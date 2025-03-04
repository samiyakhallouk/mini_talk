#include "minitalk.h"

void	send_signal(int pid, unsigned char c)
{
	int	i;
	unsigned char	tmp;

	tmp = c;
	i = 8;
	while (i > 0)
	{
		i--;
		tmp = c << i;
		if (tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(42);
	}
	
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_putstr("Invalid number of arguments");
		return (1);
	}
	
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		send_signal(pid, av[2][i]);
		i++;
	}
	return 0;
}