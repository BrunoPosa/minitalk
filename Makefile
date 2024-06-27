# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bposa <bposa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 16:32:58 by bposa             #+#    #+#              #
#    Updated: 2024/06/27 15:05:38 by bposa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# DEFINITIONS:

SERVER	=	server

CLIENT	=	client

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

SSRCS	=	server.c

SOBJCS	=	$(SSRCS:.c=.o)

CSRCS	=	client.c

COBJCS	=	$(CSRCS:.c=.o)

DEPS	=	minitalk.h

LIBPATH	=	./libft/

LIB		=	$(LIBPATH)libft.a

# RULES:

all			:	$(SERVER) $(CLIENT)

$(SERVER)	:	$(SOBJCS) $(LIB) $(DEPS)
	@$(CC) $(CFLAGS) -o $(SERVER) $(SOBJCS) $(LIB)

$(CLIENT)	:	$(COBJCS) $(LIB) $(DEPS)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(COBJCS) $(LIB)

$(LIB)		:
	@cd $(LIBPATH) && make

%.o			:	%.c $(DEPS)
	@$(CC) $(CFLAGS) -c -o $@ $<

debug		:	$(COBJCS) $(SOBJCS) $(LIB)
	@$(CC) $(CFLAGS) -g -O0 -o $(SERVER) $(SOBJCS) $(LIB)
	@$(CC) $(CFLAGS) -g -O0 -o $(CLIENT) $(COBJCS) $(LIB)

re			:	fclean all

clean		:
	@rm -rf $(SOBJCS) $(COBJCS)
	@cd $(LIBPATH) && make clean

fclean		: clean
	@rm -rf $(SERVER) $(CLIENT)
	@cd $(LIBPATH) && make fclean

.PHONY		: all re clean fclean