/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bposa <bposa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:16:43 by bposa             #+#    #+#             */
/*   Updated: 2024/06/26 20:37:33 by bposa            ###   ########.fr       */
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

static void	str_maker(char c)
{
	static char	*str = NULL;
	char		ch_str[2];

	ch_str[0] = c;
	ch_str[1] = '\0';
	if (str == NULL)
	{
		str = ft_strdup("");
		if (!str)
			end_all(&str, ERROR);
	}
	if (c == '\0')
	{
		if (ft_printf("%s\n", str) == ERROR)
			end_all(&str, ERROR);
		if (str)
			free(str);
		str = NULL;
		return ;
	}
	str = ft_strjoin(str, ch_str);
	if (str == NULL)
		end_all(&str, ERROR);
}

static void	sig_to_ch(int b)
{
	static	int		i = 0;
	static 	char	c = '\0';

	c = (c << 1) | b;
	if (++i == 8)
	{
		str_maker((char)c);
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
	struct sigaction sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &my_sighandler;
	if (ft_printf("PID: %d\n", getpid()) == ERROR)
		return (5);
	if (sigaction(SIGUSR1, &sa, NULL) == ERROR)
		return (ERROR);
	if (sigaction(SIGUSR2, &sa, NULL) == ERROR)
		return (ERROR);
	while (1)
		pause();
	return (0);
}
