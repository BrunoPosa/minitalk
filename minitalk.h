/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bposa <bposa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:26:58 by bposa             #+#    #+#             */
/*   Updated: 2024/06/24 13:46:07 by bposa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include "./libft/libft.h"
#include <stdlib.h> //for malloc
#include <signal.h> //for kill(), sigaction()..
#include <unistd.h> //for sleep(), getpid(), pause()..

int g_i = 0;

# ifndef ERROR
#  define ERROR -1
# endif

#endif
