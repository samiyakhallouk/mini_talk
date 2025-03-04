#include "minitalk.h"

int	ft_atoi(char *s)
{
   int	i;
   int	sign;
   int	r;

	i = 0;
	r = 0;
	sign = 1;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		r = r * 10 + s[i] - '0';
	}
	return (r * sign);
}

void	*ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1,"(null)", 6));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
