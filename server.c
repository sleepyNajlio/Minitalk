#include <signal.h>
#include "libft/libft.h"

void	handler(int sig)
{
	static char	c;
	static int	i;
	static int	count;

	if (count == 0)
	{
		i = 1;
		c = '\0';
		count = 0;
	}
	if (sig == SIGUSR1)
		c = c | i;
	i = i << 1;
	count++;
	if (count == 8)
	{
		write(1, &c, 1);
		count = 0;
	}
}

int	main()
{
	int	Pid;

	Pid = getpid();
	ft_putstr_fd("Server PID : ", 1);
	ft_putnbr_fd(Pid, 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	while (1)
		pause();
}