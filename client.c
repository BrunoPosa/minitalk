/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bposa <bposa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:41:53 by bposa             #+#    #+#             */
/*   Updated: 2024/06/18 22:22:51 by bposa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int ch_to_sig(int pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i <= 7)//sizeof(unsigned char) ??
	{
		if ((c >> (7 - i) & 1) == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				return (-1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (-1);
		}
		if (usleep(100) == -1)
			return (-1);
		i++;
	}

	return (0);
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;

	pid = 0;
	str = NULL;
	if (argc != 3)
		return (write(1, "no input\n", 9));

	//validate input (argv[1]/PID, argv[2])

	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str != '\0')
	{
		if (ch_to_sig(pid, *str) == -1) //char* or unsigned char* ??
			return (-1);
		str++;
	}
	return (0);
}
