/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bposa <bposa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:16:43 by bposa             #+#    #+#             */
/*   Updated: 2024/06/25 13:29:53 by bposa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	end_all(char **s, int error)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
	s = NULL;
	if (error == ERROR)
	{
		exit(1);
	}
}

/*
	printing garbage sometimes. Saved few lines using ft_strjoin(ft_strdup(""), &c) as param for line 55 [temp = strjoin]
*/
static void	str_maker(char c)
{
	static char	*str = NULL;
	char		*temp;
	char		ch_str[2];

	temp = NULL;
	ch_str[0] = c;
	ch_str[1] = '\0';
	if (!str)
	{
		str = ft_strdup("");
		if (!str)
			end_all(&str, ERROR);
	}
	if (c == '\0')
	{
		if (ft_printf("%s\n", str) == ERROR)
			end_all(&str, ERROR);
		free(str);
		str = NULL;
		return ;
	}
	temp = ft_strjoin(str, ch_str);
	if (temp == NULL)
		end_all(&str, ERROR);
	str = temp;
	temp = NULL;
}

static void	sig_to_ch(int b)
{
	static	int		i = 0;
	static 	char	c = '\0';

	c = (c << 1) | b;
	if (++i == 8)
	{
		str_maker(c);
		i = 0;
		c = '\0';
	}
}

static void	my_sighandler(int signum)
{
	if (signum == SIGUSR1)
		sig_to_ch(1);
	else if (signum == SIGUSR2)
		sig_to_ch(0);
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
