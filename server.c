/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bposa <bposa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:16:43 by bposa             #+#    #+#             */
/*   Updated: 2024/06/17 00:01:42 by bposa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
/*
	sigusr1 => b = (b << 1) | 1;
	sigusr2 => b = b << 1;

	void	put_binary(int n)
	{
		if (n >= 2)
			put_binary(n / 2);
		write(1, &"01"[n % 2], 1);
	}
*/

// char	*sig_parser(char *str, char c)
// {
	//maybe use like in GNL strjoin here, w/ malloc etc?
// 	return ();
// }

//will I need static variable? or global? to track end of 8th signal
char	sig_to_bin()
{
	return ();
}

static void	my_sighandler(int signum)
{
	if (signum == SIGUSR1)
		write(1, "\nSIGUSR1\n", 9);
	else if (signum == SIGUSR2)
		write(1, "\nSIGUSR2\n", 9);
	else
		write(1, "\nothersignal\n", 13);
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
