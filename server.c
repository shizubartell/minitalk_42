/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:52:54 by abartell          #+#    #+#             */
/*   Updated: 2022/09/22 11:25:01 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putnbr(unsigned int i)
{
	if (i > 9)
		ft_putnbr(i / 10);
	write(1, &"0123456789"[i % 10], 1);
	return (0);
}

void	byte_transfer(int signal_input)
{
	static char	str;
	static int	count;

	if (signal_input == SIGUSR1)
		str = str | 1;
	if (++count == 8)
	{
		count = 0;
		if (!str)
			write(1, "\n", 1);
		write(1, &str, 1);
		str = 0;
	}
	else
		str <<= 1;
}

int	main(void)
{
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, byte_transfer);
	signal(SIGUSR2, byte_transfer);
	while (1)
		pause();
	return (0);
}
