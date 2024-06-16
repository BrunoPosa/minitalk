/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bposa <bposa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:41:53 by bposa             #+#    #+#             */
/*   Updated: 2024/06/16 23:22:44 by bposa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	put_binary(int n)
{
	if (n >= 2)
		put_binary(n / 2);
	write(1, &"01"[n % 2], 1);
}

static int ch_to_sig(int pid, unsigned char c)
{
	int	i;
unsigned char b = '\0';
	i = 0;
	(void)pid;
	while (i < 8)
	{
		if ((c >> (7 - i) & 1) == 1)
		{
			// if (kill(pid, SIGUSR1) == -1)
			// 	return (-1);
			b = (b << 1) | 1;
		}
		else if ((c >> (7 - i) & 1) == 0)
		{
			// if (kill(pid, SIGUSR2) == -1)
			// 	return (-1);
			b = (b << 1) | 0;
		}
		i++;
		write(1, "\n\nputbinary:", 12);
		put_binary(b);
	}
	write (1, "\nb=", 3);
	write (1, &b, 1);
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
