/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bposa <bposa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:26:58 by bposa             #+#    #+#             */
/*   Updated: 2024/06/26 19:32:22 by bposa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include "./libft/libft.h"
#include <stdlib.h> //for malloc(), exit()
#include <signal.h> //for kill(), sigaction()..
#include <unistd.h> //for sleep(), getpid(), pause()..

# ifndef ERROR
#  define ERROR -1
# endif

# ifndef SUCCESS
#  define SUCCESS 0
# endif

#endif
