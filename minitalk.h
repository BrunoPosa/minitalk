/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bposa <bposa@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:26:58 by bposa             #+#    #+#             */
/*   Updated: 2024/06/15 15:05:33 by bposa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include "./libftprintf/libft.h"
#include <signal.h> //for kill(), sigaction()..
#include <unistd.h> //for sleep(), getpid(), pause()..

# ifndef ERROR
#  define ERROR -1
# endif

#endif