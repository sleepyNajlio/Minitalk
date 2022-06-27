/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nloutfi <nloutfi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:44:36 by nloutfi           #+#    #+#             */
/*   Updated: 2022/06/27 23:42:24 by nloutfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void f_error()
{
	ft_putstr_fd("ERROR", 1);
	exit(0);
}

void	bit_sender(char *str, int pid)
{
	int	i;
	int	j;
	
	i = 0;
	while(*(str + i))
	{
		j = 0;
		while(j < 8)
		{
			if (*(str + i) & 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					f_error();
			}
			else if (kill(pid, SIGUSR2) == -1)
				f_error();
			*(str + i) = *(str + i) >> 1;
			j++;
			usleep(50);
		}
		i++;
	}
}


int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		f_error();
	pid = ft_atoi(av[1]);
	bit_sender(av[2], pid);
	
}