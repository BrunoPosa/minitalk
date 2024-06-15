/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bposa <bposa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:41:53 by bposa             #+#    #+#             */
/*   Updated: 2024/06/15 16:04:37 by bposa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


int	main(int argc, char *argv[])
{
	int	pid;

	pid = 0;
	if (argc != 3)
		return (write(1, "no input\n", 9));
	pid = ft_atoi(argv[1]);
	ft_printf("pid of serves from client: %d\n", pid);
	if (argv[2][0] == '1')
		kill(pid, SIGUSR1);
	else if (argv[2][0] == '2')
		kill(pid, SIGUSR2);
	else
		kill(pid, SIGINT);
	return (0);
}