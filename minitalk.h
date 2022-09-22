/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartell <abartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:53:37 by abartell          #+#    #+#             */
/*   Updated: 2022/09/22 11:23:33 by abartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

void	byte_transfer(int signal_input);
void	client_response(int pid, char *str);
int		ft_atoi(const char *nptr);
int		ft_putnbr(unsigned int i);

#endif