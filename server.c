#include "minitalk.h"


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
	pid_t	pid;
	
	pid = getgid();
	ft_putstr("PID -> ");
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	while (1)
		pause();
	return 0;
}
