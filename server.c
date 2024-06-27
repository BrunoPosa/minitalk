/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bposa <bposa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:16:43 by bposa             #+#    #+#             */
/*   Updated: 2024/06/27 16:37:26 by bposa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*g_str = NULL;

static void	clean_end(int status)
{
	if (g_str)
	{
		free(g_str);
		g_str = NULL;
	}
	if (status == ERROR)
		exit(EXIT_FAILURE);
	else if (status == SUCCESS)
		exit(EXIT_SUCCESS);
}

static void	str_maker(char c)
{
	char	*temp;
	char	ch_str[2];

	temp = NULL;
	ch_str[0] = c;
	ch_str[1] = '\0';
	if (g_str == NULL)
	{
		g_str = ft_strdup("");
		if (!g_str)
			clean_end(ERROR);
	}
	if (c == '\0')
	{
		if (ft_printf("%s\n", g_str) < 0)
			clean_end(ERROR);
		clean_end(KEEP_RUNNING);
		return ;
	}
	temp = ft_strjoin(g_str, ch_str);
	if (temp == NULL)
		clean_end(ERROR);
	free(g_str);
	g_str = temp;
	temp = NULL;
}

static void	sig_to_ch(int b)
{
	static int	i = 0;
	static char	c = '\0';

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

/*
	Need to end cleanly on errors and upon SIGINT. Currently leaking
*/
int	main(void)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(sa));
	if (sigemptyset(&sa.sa_mask) == ERROR)
		return (ERROR);
	if (sigaddset(&sa.sa_mask, SIGUSR1) == ERROR)
		return (ERROR);
	if (sigaddset(&sa.sa_mask, SIGUSR2) == ERROR)
		return (ERROR);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &my_sighandler;
	if (ft_printf("PID: %d\n", getpid()) < 0)
		clean_end(ERROR);
	if (sigaction(SIGUSR1, &sa, NULL) == ERROR)
		clean_end(ERROR);
	if (sigaction(SIGUSR2, &sa, NULL) == ERROR)
		clean_end(ERROR);
	while (1)
		pause();
	clean_end(SUCCESS);
}
