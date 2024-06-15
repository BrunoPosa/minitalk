/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bposa <bposa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:16:43 by bposa             #+#    #+#             */
/*   Updated: 2024/06/15 15:44:28 by bposa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	my_sighandler(int signum)
{
	if (signum == SIGUSR1)
		write(1, "\nSIGUSR1\n", 9);
	else if (signum == SIGUSR2)
		write(1, "\nSIGUSR2\n", 9);
	else
		write(1, "\nsome signal\n", 13);
}

int	main(void)
{
	int	pid;
	struct sigaction sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = &my_sighandler;
	pid = getpid();
	if (ft_printf("PID: %d\n", pid) == ERROR)
		return (5);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (-1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (-1);
	while (1)
		pause();
	return (0);
}
