/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:52:45 by abartell          #+#    #+#             */
/*   Updated: 2022/09/22 12:08:04 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	neg;

	neg = 1;
	i = 0;
	result = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		neg = -1;
	if (nptr[i] == '+' || neg == -1)
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * neg);
}

void	client_response(int pid, char *str)
{
	int		count;
	char	c;

	count = 8;
	while (*str)
	{
		count = 8;
		c = *(str++);
		while (count--)
		{
			if (c >> count & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(300);
		}
	}
	count = 8;
	while (count--)
	{
		kill(pid, SIGUSR2);
		usleep(300);
	}
}

int	main(int argc, char **argv)
{
	if (argc < 3 || argc > 3)
	{
		write(1, "Wrong input amount of arguments!\n", 34);
		return (0);
	}
	client_response(ft_atoi(argv[1]), argv[2]);
}
