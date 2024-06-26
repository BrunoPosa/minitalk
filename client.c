/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bposa <bposa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:41:53 by bposa             #+#    #+#             */
/*   Updated: 2024/06/26 18:52:36 by bposa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int ch_to_sig(int pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if ((c >> (7 - i) & 1) == 1)
		{
			if (kill(pid, SIGUSR1) == ERROR)
				return (ERROR);
		}
		else
		{
			if (kill(pid, SIGUSR2) == ERROR)
				return (ERROR);
		}
		if (usleep(200) == ERROR)
			return (ERROR);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;

	if (argc != 3 || (argc == 3 && argv[1][0] == '\0'))
		return (write(1, "Please try with 2 arguments, 1st is PID and 2nd the string to send.\n", 68));
	pid = ft_atoi(argv[1]);
	if (pid == ERROR || pid < 3 || pid > 4194304)
		return (write(1, "Invalid PID\n", 12));
	str = argv[2];
	if (!str)
		return (ERROR);
	while (*str != '\0')
	{
		if (ch_to_sig(pid, *str) == ERROR)
			return (ERROR);
		str++;
	}
	return (ch_to_sig(pid, *str));
}
